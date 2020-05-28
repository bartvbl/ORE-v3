#pragma once

#include <ore/resources/resourceTypes/material/Material.h>
#include <string>
#include <ore/geom/vec3.h>

namespace ore {
    namespace resources {
        struct MeshPart {
            std::string name;
            unsigned int indexBufferStartIndex;
            unsigned int indexBufferEndIndex;

            ore::resources::Material material;
            ore::geom::vec3 pivot;
        };
    }
}