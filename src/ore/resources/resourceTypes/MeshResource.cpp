#include <iostream>
#include <json.hpp>
#include <fstream>
#include <fast_obj.h>
#include <ore/gl/vao/GeometryBufferGenerator.h>
#include <thread>
#include <ore/utilities/Logger.h>
#include <g3log/g3log.hpp>
#include "MeshResource.h"

// Not a member function because fast_obj can not be included from MeshResource.h.
void visitMeshPart(const nlohmann::json &partJSON,
                   ore::resources::Mesh &mesh,
                   const unsigned int currentPartIndex,
                   const fastObjMesh* temporaryMesh,
                   const ore::filesystem::path& modelFileLocation,
                   const ore::filesystem::path& objectFileLocation) {
    mesh.parts.at(currentPartIndex).name = std::string(partJSON["name"]);

    std::string objGroupName = partJSON["nameInObjectFile"];
    if(!objGroupName.empty()) {
        mesh.parts.at(currentPartIndex).containsGeometry = true;

        unsigned int groupIndex = 0;
        for(; groupIndex < temporaryMesh->group_count; groupIndex++) {
            fastObjGroup group = temporaryMesh->groups[groupIndex];
            if(group.name == nullptr) {
                LOG(FATAL) << "The OBJ file located at '" << objectFileLocation.string() << "' does not contain any groups. Please re-export your OBJ file to use groups to denote object parts.";
            }
            if(std::string(group.name) == objGroupName) {
                break;
            }
        }

        if(groupIndex == temporaryMesh->group_count) {
            std::stringstream errorMessage;
            errorMessage << "The part named \"" + objGroupName +
                            "\" listed in the model file \"" + modelFileLocation.string() +
                            "\" was not found in the OBJ file \"" + objectFileLocation.string() + "\"." << std::endl
                         << "Candidates are:" << std::endl;
            for(unsigned int i = 0; i < temporaryMesh->group_count; i++) {
                fastObjGroup group = temporaryMesh->groups[i];
                errorMessage << "    - " << std::string(group.name) << std::endl;
            }
            LOG(FATAL) << errorMessage.str();
        }

        fastObjGroup group = temporaryMesh->groups[groupIndex];

        mesh.parts.at(currentPartIndex).indexBufferStartIndex = mesh.geometry.indices.size();
        mesh.parts.at(currentPartIndex).indexCount = group.face_count * 3;

        for(unsigned int faceIndex = 0; faceIndex < group.face_count; faceIndex++) {
            // Ensure faces are triangles. Can probably fix this at a later date, but for now it gives an error.
            unsigned int verticesPerFace = temporaryMesh->face_vertices[faceIndex + group.face_offset];
            if(verticesPerFace != 3) {
                LOG(FATAL) << "This OBJ loader only supports 3 vertices per face. The object " + objectFileLocation.string() + " in model file " + modelFileLocation.string() + " contains a face with " + std::to_string(verticesPerFace) + " vertices.\nYou can usually solve this problem by re-exporting the object from a 3D model editor, and selecting the OBJ export option that forces triangle faces.";
            }

            for(unsigned int i = 0; i < verticesPerFace; i++) {
                fastObjIndex index = temporaryMesh->indices[3 * faceIndex + i + group.index_offset];

                mesh.geometry.vertices.emplace_back(
                        temporaryMesh->positions[3 * index.p + 0],
                        temporaryMesh->positions[3 * index.p + 1],
                        temporaryMesh->positions[3 * index.p + 2]);

                if(mesh.geometry.hasTextures) {
                    mesh.geometry.textureCoordinates.emplace_back(
                            temporaryMesh->texcoords[2 * index.t + 0],
                            temporaryMesh->texcoords[2 * index.t + 1]);
                }

                if(mesh.geometry.hasNormals) {
                    mesh.geometry.normals.emplace_back(
                            temporaryMesh->normals[3 * index.n + 0],
                            temporaryMesh->normals[3 * index.n + 1],
                            temporaryMesh->normals[3 * index.n + 2]);
                }

                mesh.geometry.indices.push_back(mesh.geometry.indices.size());
            }
        }

        mesh.parts.at(currentPartIndex).materialIndex = temporaryMesh->face_materials[group.face_offset];
    } else {
        mesh.parts.at(currentPartIndex).containsGeometry = false;
    }

    mesh.parts.at(currentPartIndex).pivot.x = partJSON["pivot"][0];
    mesh.parts.at(currentPartIndex).pivot.y = partJSON["pivot"][1];
    mesh.parts.at(currentPartIndex).pivot.z = partJSON["pivot"][2];

    mesh.parts.at(currentPartIndex).childNodeCount = partJSON["children"].size();

    for(unsigned int i = 0; i < partJSON["children"].size(); i++) {
        mesh.parts.emplace_back();
        visitMeshPart(partJSON["children"][i], mesh, i, temporaryMesh, modelFileLocation, objectFileLocation);
    }
}

void loadMesh(const ore::filesystem::path &modelFileLocation,
              const nlohmann::json &modelFileContents,
              ore::filesystem::path &objectFileLocation,
              ore::resources::Mesh &mesh) {
    fastObjMesh* temporaryMesh = fast_obj_read(objectFileLocation.c_str());

    mesh.geometry.hasNormalMap = false;
    mesh.geometry.hasNormals = temporaryMesh->indices[0].n != 0;
    mesh.geometry.hasTextures = temporaryMesh->indices[0].t != 1;

    // Allocate space
    mesh.geometry.vertices.reserve(3 * temporaryMesh->face_count);
    mesh.geometry.normals.reserve(3 * temporaryMesh->face_count);
    mesh.geometry.textureCoordinates.reserve(2 * temporaryMesh->face_count);
    mesh.geometry.indices.reserve(3 * temporaryMesh->face_count);

    // Construct part tree and fill buffers
    visitMeshPart(modelFileContents["partStructure"], mesh, 0, temporaryMesh, modelFileLocation, objectFileLocation);

    // Process materials (load textures)
    mesh.materials.reserve(temporaryMesh->material_count);
    for(unsigned int materialIndex = 0; materialIndex < temporaryMesh->material_count; materialIndex++) {
        fastObjMaterial material = temporaryMesh->materials[materialIndex];
        mesh.materials.emplace_back(
                std::string(material.name),
                ore::geom::vec3(material.Ka),
                ore::geom::vec3(material.Kd),
                ore::geom::vec3(material.Ks),
                ore::geom::vec3(material.Ke),
                material.d,
                material.map_Kd.path != nullptr ?
                std::string(material.map_Kd.path) : "",
                material.map_bump.path != nullptr ?
                std::string(material.map_bump.path) : "");
        mesh.materials.at(mesh.materials.size() - 1).load();
    }

    fast_obj_destroy(temporaryMesh);
}

void ore::resources::MeshResource::loadMDLFile(const ore::filesystem::path &modelFileLocation) {
    ore::filesystem::path containingDirectory = modelFileLocation.parent_path();
    nlohmann::json modelFileContents;
    std::fstream fileStream(modelFileLocation, std::ios::in);
    try {
        fileStream >> modelFileContents;
    } catch(nlohmann::detail::exception &e) {
        LOG(FATAL) << "Failed to load mesh located at " << modelFileLocation << std::endl << "Reason:" << std::endl << e.what() << std::endl;
        throw std::runtime_error("Resource failed to load.");
    }
    fileStream.close();
    name = modelFileLocation.string();

    assert(modelFileContents["meta"]["version"] == 1);

    std::string relativeObjectFileLocation = modelFileContents["modelFile"];
    ore::filesystem::path objectFileLocation = containingDirectory / relativeObjectFileLocation;

    loadMesh(modelFileLocation, modelFileContents, objectFileLocation, this->mesh);

}



void ore::resources::MeshResource::loadOBJFile(const ore::filesystem::path &modelFileLocation) {

}

void ore::resources::MeshResource::load(const ore::filesystem::path &modelFileLocation) {
    std::string extension = modelFileLocation.extension();
    if(extension == ".mdl") {
        loadMDLFile(modelFileLocation);
    } else if(extension == ".obj") {
        loadOBJFile(modelFileLocation);
    }
}

bool ore::resources::MeshResource::requiresMainThread() {
    return true;
}

void ore::resources::MeshResource::completeLoadOnMainThread() {
    geometryBuffer = ore::gl::generateGeometryBuffer(mesh.geometry);

    for(auto & material : mesh.materials) {
        material.completeOnMainThread();
    }
}

void ore::resources::MeshResource::destroy() {

}

ore::MeshNode *ore::resources::MeshResource::createInstance() {
    return new MeshNode();
}



