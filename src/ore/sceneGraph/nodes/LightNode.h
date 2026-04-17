#pragma once

#include <ore/sceneGraph/nodes/ContainerNode.h>
#include <ore/gl/lighting/Light.h>
#include <ore/core/Constants.h>
#include <array>

#include "GeometryNode.h"
#include "ShaderNode.h"
#include "ore/gl/shader/ShaderLoader.h"
#include "ore/gl/shader/ShaderSource.h"
#include "ore/gl/shapes/PrimitiveGenerator.h"

namespace ore {
    namespace scene {
        class LightNode : public ore::scene::ContainerNode {
        private:
            std::array<ore::gl::Light, ore::MAX_LIGHT_SOURCES> lightSources;
            ore::scene::GeometryNode lightConeNode;
            ore::scene::CoordinateNode lightConeLocationNode;
            ore::resources::Shader lightBeamShader;
            unsigned int lightSourceCount = 0;
        public:
            LightNode() : ore::scene::ContainerNode("Light Node") {
                lightConeNode = gl::PrimitiveGenerator::generateInvertedConeBuffer();
                lightConeLocationNode.getChildren()->push_back(&lightConeNode);

                ore::gl::ShaderSource shaderSource;
                shaderSource.vertexShaderSource = "#version 430 core\n\
                    layout(location = 0) in vec3 position;\n\
                    layout(location = 1) in vec3 normal;\n\
                    layout(location = 2) in vec2 texCoord;\n\
                    layout(location = 4) in vec3 normalMapTangent;\n\
                    layout(location = 5) in vec3 normalMapBitangent;\n\
                    layout(location = 1) out vec3 out_position;\n\
                    layout(location = 4) uniform int enableNormalMaps;\n\
                    layout(location = 30) uniform mat4x4 MVP;\n\
                    layout(location = 31) uniform mat4x4 MV;\n\
                    layout(location = 32) uniform mat4x4 normalMatrix;\n\
                    layout(location = 33) uniform mat4x4 shadowMVP[4];\n\
                    layout(location = 90) uniform int activeShadowLightCount;\n\
                    void main()\n\
                    {\n\
                        out_position = vec3(MV * vec4(position, 1.0));\n\
                        gl_Position = MVP * vec4(position, 1.0f);\n\
                    }\
                ";
                shaderSource.fragmentShaderSource = "#version 430 core\n\
                    layout(location = 1) uniform int enableTexturing;\n\
                    layout(location = 2) uniform int enableLighting;\n\
                    layout(location = 3) uniform int enableShadows;\n\
                    layout(location = 4) uniform int enableNormalMaps;\n\
                    layout(location = 20) uniform vec4 materialDiffuseColour;\n\
                    layout(location = 49) uniform int activeLightCount;\n\
                    layout(location = 50) uniform vec3 lightPositions[16];\n\
                    layout(location = 66) uniform float lightAttenuations[16];\n\
                    layout(location = 90) uniform int activeShadowLightCount;\n\
                    layout(location = 91) uniform vec3 shadowLightPositions[4];\n\
                    layout(location = 95) uniform float shadowLightAttenuations[4];\n\
                    layout(location = 99) uniform int disableLight[4];\n\
                    out vec4 color;\n\
                    void main()\n\
                    {\n\
                        color = vec4(0.7, 0.9, 1, 0.2);\n\
                    }";
                lightBeamShader = ore::gl::createShader(&shaderSource, "Light beam");
            }

            void preRender(ore::RenderState &state) override;

            void render(ore::RenderState &state) override;

            void postRender(ore::RenderState &state) override;

            void addLight(ore::gl::Light &light);

            void clearLights();
        };
    }
}
