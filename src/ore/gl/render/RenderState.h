#pragma once

#include <glm/glm.hpp>

namespace ore {
    struct WindowDimensionsRenderState {
        unsigned int width = 1920;
        unsigned int height = 1080;
    };

    struct TransformationRenderState {
        glm::mat4 model = glm::mat4(1.0);
        glm::mat4 orthographicView = glm::mat4(1.0);
        glm::mat4 perspectiveView = glm::mat4(1.0);
        glm::mat4 projection = glm::mat4(1.0);
    };

    struct RenderState {
        TransformationRenderState transformations;
        WindowDimensionsRenderState window;
    };
}