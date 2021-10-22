#pragma once

#include <ore/resources/resourceTypes/material/Material.h>
#include <string>
#include <ore/geom/vec3.h>

namespace ore {
    namespace resources {
        struct MeshPart {
            std::string name;
            bool containsGeometry = false;
            unsigned int indexBufferStartIndex = 0;
            unsigned int indexCount = 0;

            unsigned int materialIndex = 0;
            ore::geom::vec3 pivot = {0, 0, 0};

            unsigned int childNodeCount = 0;
        };
    }
}