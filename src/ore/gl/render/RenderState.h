#pragma once

#include <glm/glm.hpp>
#include <ore/resources/resourceTypes/shader/Shader.h>
#include <ore/resources/resourceTypes/texture/Texture.h>
#include <ore/geom/vec4.h>

namespace ore {
    struct WindowDimensionsRenderState {
        unsigned int width = 1920;
        unsigned int height = 1080;
    };

    struct TransformationRenderState {
        glm::mat4 model = glm::mat4(1.0);
        glm::mat4 view = glm::mat4(1.0);
        glm::mat4 projection = glm::mat4(1.0);

        glm::mat4 shadowMVP = glm::mat4(1.0);
    };

    class ShaderUniformRenderState {
    public:
        void setModelMatrix(glm::mat4 modelMatrix);
        void setModelViewMatrix(glm::mat4 modelMatrix);
        void setProjection(glm::mat4 projectionMatrix);
        void setTexture(unsigned int ID, resources::Texture texture);

        void setLightPositions(const unsigned int baseUniformID, float *positionList, unsigned int count);

        void setColour(const unsigned int uniformID, ore::geom::vec4 colour);
    };

    struct RenderState {
        TransformationRenderState transformations;
        WindowDimensionsRenderState window;
        ShaderUniformRenderState uniforms;
        ore::resources::Shader currentActiveShader;
    };
}