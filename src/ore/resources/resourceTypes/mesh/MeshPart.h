#pragma once

#include <ore/resources/resourceTypes/material/Material.h>
#include <string>
#include <glm/glm.hpp>

namespace ore {
    namespace resources {
        struct MeshPart {
            std::string name;
            unsigned int indexBufferStartIndex;
            unsigned int indexBufferEndIndex;

            ore::resources::Material material;
            glm::vec3 pivot;
        };
    }
}