#pragma once

#include <glm/glm.hpp>
#include <ore/resources/resourceTypes/shader/Shader.h>
#include <ore/resources/resourceTypes/texture/Texture.h>
#include <ore/geom/vec4.h>
#include <array>
#include <ore/core/Constants.h>
#include <ore/gl/shader/ShadingConfiguration.h>

namespace ore {
    struct WindowDimensionsRenderState {
        unsigned int width = 1920;
        unsigned int height = 1080;
    };

    struct TransformationRenderState {
        glm::mat4 model = glm::mat4(1.0);
        glm::mat4 view = glm::mat4(1.0);
        glm::mat4 projection = glm::mat4(1.0);

        std::array<glm::mat4, ore::MAX_SHADOW_LIGHT_SOURCES> shadowVP = {glm::mat4(1.0), glm::mat4(1.0), glm::mat4(1.0), glm::mat4(1.0)};
    };

    class ShaderUniformRenderState {
    public:
        glm::vec4 diffuseColour = {1, 1, 1, 1};

        void setTexture(unsigned int ID, resources::Texture texture);

        void setLightPositions(const unsigned int baseUniformID, const unsigned int arrayLengthUniformID, float *positionList, unsigned int count);

        void setDiffuseColour(const unsigned int uniformID, glm::vec4 colour);

        void setInteger(const unsigned int uniformID, unsigned int value);
    };

    struct RenderState {
        TransformationRenderState transformations;
        WindowDimensionsRenderState window;
        ShaderUniformRenderState uniforms;
        ore::resources::Shader currentActiveShader;
        ore::gl::ShadingConfiguration shading;
    };
}