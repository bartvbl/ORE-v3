#pragma once

#include <glm/glm.hpp>

namespace ore {
    struct WindowDimensionsRenderState {
        unsigned int width = 1920;
        unsigned int height = 1080;
    };

    struct TransformationRenderState {
        glm::mat4 model = glm::mat4(1.0);
        glm::mat4 view = glm::mat4(1.0);
        glm::mat4 projection = glm::mat4(1.0);
    };

    class ShaderUniformRenderState {
        void setModelMatrix(glm::mat4 modelMatrix);
        void setModelViewMatrix(glm::mat4 modelMatrix);
        void setProjection(glm::mat4 projectionMatrix);
    };

    struct RenderState {
        TransformationRenderState transformations;
        WindowDimensionsRenderState window;
        ShaderUniformRenderState uniforms;
    };
}