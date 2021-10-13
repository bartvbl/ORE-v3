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
void visitMeshPart(nlohmann::json* const partJSON, ore::resources::Mesh* const mesh, ore::resources::MeshPart* currentPart, fastObjMesh* const temporaryMesh, const ore::filesystem::path* modelFileLocation, const ore::filesystem::path* objectFileLocation) {
    currentPart->name = std::string((*partJSON)["name"]);

    std::string objGroupName = (*partJSON)["nameInObjectFile"];
    if(!objGroupName.empty()) {
        currentPart->containsGeometry = true;

        unsigned int groupIndex = 0;
        for(; groupIndex < temporaryMesh->group_count; groupIndex++) {
            fastObjGroup group = temporaryMesh->groups[groupIndex];
            if(std::string(group.name) == objGroupName) {
                break;
            }
        }

        if(groupIndex == temporaryMesh->group_count) {
            std::stringstream errorMessage;
            errorMessage << "The part named \"" + objGroupName +
                            "\" listed in the model file \"" + modelFileLocation->string() +
                            "\" was not found in the OBJ file \"" + objectFileLocation->string() + "\"." << std::endl
                         << "Candidates are:" << std::endl;
            for(unsigned int i = 0; i < temporaryMesh->group_count; i++) {
                fastObjGroup group = temporaryMesh->groups[i];
                errorMessage << "    - " << std::string(group.name) << std::endl;
            }
            LOG(FATAL) << errorMessage.str();
                       ;

        }

        fastObjGroup group = temporaryMesh->groups[groupIndex];

        currentPart->indexBufferStartIndex = mesh->geometry.indices.size();
        currentPart->indexCount = group.face_count * 3;

        for(unsigned int faceIndex = 0; faceIndex < group.face_count; faceIndex++) {
            // Ensure faces are triangles. Can probably fix this at a later date, but for now it gives an error.
            unsigned int verticesPerFace = temporaryMesh->face_vertices[faceIndex + group.face_offset];
            if(verticesPerFace != 3) {
                throw std::runtime_error("This OBJ loader only supports 3 vertices per face. The object " + objectFileLocation->string() + " in model file " + modelFileLocation->string() + " contains a face with " + std::to_string(verticesPerFace) + " vertices.\nYou can usually solve this problem by re-exporting the object from a 3D model editor, and selecting the OBJ export option that forces triangle faces.");
            }

            for(unsigned int i = 0; i < verticesPerFace; i++) {
                fastObjIndex index = temporaryMesh->indices[3 * faceIndex + i + group.index_offset];

                mesh->geometry.vertices.emplace_back(
                        temporaryMesh->positions[3 * index.p + 0],
                        temporaryMesh->positions[3 * index.p + 1],
                        temporaryMesh->positions[3 * index.p + 2]);

                if(mesh->geometry.hasTextures) {
                    mesh->geometry.textureCoordinates.emplace_back(
                            temporaryMesh->texcoords[2 * index.t + 0],
                            temporaryMesh->texcoords[2 * index.t + 1]);
                }

                if(mesh->geometry.hasNormals) {
                    mesh->geometry.normals.emplace_back(
                            temporaryMesh->normals[3 * index.n + 0],
                            temporaryMesh->normals[3 * index.n + 1],
                            temporaryMesh->normals[3 * index.n + 2]);
                }

                mesh->geometry.indices.push_back(mesh->geometry.indices.size());
            }
        }

        fastObjMaterial material = temporaryMesh->materials[temporaryMesh->face_materials[group.face_offset]];
        currentPart->materialName = std::string(material.name);
    } else {
        currentPart->containsGeometry = false;
    }

    currentPart->pivot.x = (*partJSON)["pivot"][0];
    currentPart->pivot.y = (*partJSON)["pivot"][1];
    currentPart->pivot.z = (*partJSON)["pivot"][2];

    for(unsigned int i = 0; i < (*partJSON)["children"].size(); i++) {
        currentPart->childParts.emplace_back();
        visitMeshPart(&(*partJSON)["children"][i], mesh, &currentPart->childParts.at(i), temporaryMesh, modelFileLocation, objectFileLocation);
    }
}

void ore::resources::MeshResource::load(const ore::filesystem::path &modelFileLocation) {
    if(!ore::filesystem::exists(modelFileLocation)) {
        std::cout << "";
    }

    ore::filesystem::path containingDirectory = modelFileLocation.parent_path();
    nlohmann::json modelFileContents;
    std::fstream fileStream(modelFileLocation, std::ios::in);
    try {
        fileStream >> modelFileContents;
    } catch(nlohmann::detail::exception e) {
        LOG(FATAL) << "Failed to load mesh located at " << modelFileLocation << std::endl << "Reason:" << std::endl << e.what() << std::endl;
        throw std::runtime_error("Resource failed to load.");
    }
    fileStream.close();
    name = modelFileLocation.string();

    assert(modelFileContents["meta"]["version"] == 1);

    std::string relativeObjectFileLocation = modelFileContents["modelFile"];
    ore::filesystem::path objectFileLocation = containingDirectory / relativeObjectFileLocation;

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
    visitMeshPart(&modelFileContents["partStructure"], &this->mesh, &this->mesh.rootPart, temporaryMesh, &modelFileLocation, &objectFileLocation);

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