#include <iostream>
#include <json.hpp>
#include <fstream>
#include <fast_obj.h>
#include "MeshResource.h"

#define _array_header(_arr)     ((fastObjUInt*)(_arr)-2)
#define _array_size(_arr)       (_array_header(_arr)[0])
#define array_clean(_arr)       ((_arr) ? free(_array_header(_arr)), 0 : 0)
#define array_size(_arr)        ((_arr) ? _array_size(_arr) : 0)

void ore::resources::MeshResource::load(const ore::filesystem::path &modelFileLocation) {
    ore::filesystem::path containingDirectory = modelFileLocation.parent_path();
    nlohmann::json modelFileContents;
    std::fstream fileStream(modelFileLocation, std::ios::in);
    fileStream >> modelFileContents;
    fileStream.close();

    assert(modelFileContents["meta"]["version"] == 1);

    std::string relativeObjectFileLocation = modelFileContents["modelFile"];
    ore::filesystem::path objectFileLocation = containingDirectory / relativeObjectFileLocation;

    fastObjMesh* mesh = fast_obj_read(objectFileLocation.c_str());

    for(unsigned int group = 0; group < mesh->group_count; group++) {

    }


    // Modified version of fast_obj_destroy(), because we want to keep the geometry buffers
    unsigned int ii;

    for (ii = 0; ii < array_size(mesh->groups); ii++)
        free(mesh->groups[ii].name);

    for (ii = 0; ii < array_size(mesh->materials); ii++) {
        free(mesh->materials[ii].map_Ka.name);
        free(mesh->materials[ii].map_Ka.path);
        free(mesh->materials[ii].map_Kd.name);
        free(mesh->materials[ii].map_Kd.path);
        free(mesh->materials[ii].map_Ks.name);
        free(mesh->materials[ii].map_Ks.path);
        free(mesh->materials[ii].map_Ke.name);
        free(mesh->materials[ii].map_Ke.path);
        free(mesh->materials[ii].map_Kt.name);
        free(mesh->materials[ii].map_Kt.path);
        free(mesh->materials[ii].map_Ns.name);
        free(mesh->materials[ii].map_Ns.path);
        free(mesh->materials[ii].map_Ni.name);
        free(mesh->materials[ii].map_Ni.path);
        free(mesh->materials[ii].map_d.name);
        free(mesh->materials[ii].map_d.path);
        free(mesh->materials[ii].map_bump.name);
        free(mesh->materials[ii].map_bump.path);

        free(mesh->materials[ii].name);
    }
    // DISABLED BECAUSE WE WANT TO KEEP THESE!
    //array_clean(mesh->positions);
    //array_clean(mesh->texcoords);
    //array_clean(mesh->normals);

    array_clean(mesh->face_vertices);
    array_clean(mesh->face_materials);
    array_clean(mesh->indices);
    array_clean(mesh->groups);
    array_clean(mesh->materials);

    free(mesh);
}

bool ore::resources::MeshResource::requiresMainThread() {
    return true;
}

void ore::resources::MeshResource::completeLoadOnMainThread() {
}

void ore::resources::MeshResource::destroy() {

}