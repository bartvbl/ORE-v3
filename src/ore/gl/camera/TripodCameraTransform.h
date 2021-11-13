#pragma once
#include <glm/glm.hpp>

namespace ore {
    namespace gl {
        glm::mat4 computeTripodViewTransformation(glm::mat4 &modelMatrix, glm::vec3 position, glm::vec3 rotation);
    }
}