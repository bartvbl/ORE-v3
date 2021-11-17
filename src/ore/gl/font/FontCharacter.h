#pragma once
#include <glm/glm.hpp>

namespace ore {
    namespace gl {
        struct FontCharacter {
            glm::vec2 textureCoordinatesBottomLeft = {0, 0};
            glm::vec2 textureCoordinatesTopRight = {0, 0};
            float advancePixels = 0;
            glm::vec2 sizePixels = {0, 0};
            glm::vec2 bearingPixels = {0, 0};
        };
    }
}
