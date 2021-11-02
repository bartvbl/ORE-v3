#pragma once
#include "glm/glm.hpp"

namespace ore {
    struct RelativeTransformation {
        glm::vec3 position = {0, 0, 0};
        glm::vec3 rotation = {0, 0, 0};
        float scale = 1;
    };
}

