#include <iostream>
#include <json.hpp>
#include <fstream>
#include <fast_obj.h>
#include <ore/gl/vao/GeometryBufferGenerator.h>
#include <thread>
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
            throw std::runtime_error(
                    "The part named \"" + objGroupName +
                    "\" listed in the model file \"" + modelFileLocation->string() +
                    "\" was not found in the OBJ file \"" + objectFileLocation->string() + "\".");
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

            fastObjIndex index = temporaryMesh->indices[3 * faceIndex + group.index_offset];

            assert(index.p + 2 - 1 <= temporaryMesh->position_count);
            mesh->geometry.vertices.emplace_back(
                    temporaryMesh->positions[index.p + 0 - 1],
                    temporaryMesh->positions[index.p + 1 - 1],
                    temporaryMesh->positions[index.p + 2 - 1]);

            if(mesh->geometry.hasTextures) {
                assert(index.t + 1 - 1 <= temporaryMesh->texcoord_count);
                mesh->geometry.textureCoordinates.emplace_back(
                        temporaryMesh->texcoords[index.t + 0 - 1],
                        temporaryMesh->texcoords[index.t + 1 - 1]);
            }

            if(mesh->geometry.hasNormals) {
                assert(index.n + 2 - 1 <= temporaryMesh->normal_count);
                mesh->geometry.normals.emplace_back(
                        temporaryMesh->normals[index.n + 0 - 1],
                        temporaryMesh->normals[index.n + 1 - 1],
                        temporaryMesh->normals[index.n + 2 - 1]);
            }

            mesh->geometry.indices.push_back(mesh->geometry.indices.size());
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
    ore::filesystem::path containingDirectory = modelFileLocation.parent_path();
    nlohmann::json modelFileContents;
    std::fstream fileStream(modelFileLocation, std::ios::in);
    fileStream >> modelFileContents;
    fileStream.close();
    name = modelFileLocation.string();

    assert(modelFileContents["meta"]["version"] == 1);

    std::string relativeObjectFileLocation = modelFileContents["modelFile"];
    ore::filesystem::path objectFileLocation = containingDirectory / relativeObjectFileLocation;

    fastObjMesh* temporaryMesh = fast_obj_read(objectFileLocation.c_str());

    mesh.geometry.hasNormalMap = false;
    mesh.geometry.hasNormals = temporaryMesh->indices[0].n != 0;
    mesh.geometry.hasTextures = temporaryMesh->indices[0].t != 0;

    // Allocate space
    mesh.geometry.vertices.reserve(temporaryMesh->face_count);
    mesh.geometry.normals.reserve(temporaryMesh->face_count);
    mesh.geometry.textureCoordinates.reserve(temporaryMesh->face_count);
    mesh.geometry.indices.reserve(temporaryMesh->face_count);

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