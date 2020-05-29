#pragma once

#include <ore/resources/resourceTypes/material/Material.h>
#include <string>
#include <ore/geom/vec3.h>

namespace ore {
    namespace resources {
        struct MeshPart {
            std::string name;
            bool containsGeometry;
            unsigned int indexBufferStartIndex;
            unsigned int indexCount;

            std::string materialName;
            ore::geom::vec3 pivot;

            std::vector<ore::resources::MeshPart> childParts;
        };
    }
}