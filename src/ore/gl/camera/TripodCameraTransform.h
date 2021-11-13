#pragma once
#include <glm/glm.hpp>

namespace ore {
    namespace gl {
        glm::mat4 computeTripodViewTransformation(glm::vec3 position, glm::vec3 rotation);
    }
}