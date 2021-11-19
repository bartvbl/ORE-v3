#pragma once

#include <ore/sceneGraph/nodes/ContainerNode.h>
#include <ore/sceneGraph/nodes/ShaderNode.h>
#include <ore/gl/frameBuffer/FrameBuffer.h>
#include <ore/gl/lighting/Light.h>
#include <ore/world/GameWorld.h>
#include <ore/resources/resourceTypes/texture/ShadowTexture.h>
#include <ore/core/Constants.h>

namespace ore {
    namespace scene {
        class ShadowNode : public ore::scene::ContainerNode {
        private:
            const unsigned int SHADOW_MAP_WIDTH = 2048;
            const unsigned int SHADOW_MAP_HEIGHT = 2048;

            ore::scene::ShaderNode depthPassShaderNode;
            ore::scene::ShaderNode shadowShaderNode;
            ore::scene::ContainerNode shadowedSceneContentsNode;

            std::array<ore::gl::Light, ore::MAX_SHADOW_LIGHT_SOURCES> lightSources;
            std::array<ore::resources::ShadowTexture, ore::MAX_SHADOW_LIGHT_SOURCES> textures;
            std::array<ore::gl::FrameBuffer, ore::MAX_SHADOW_LIGHT_SOURCES> frameBuffers;
            unsigned int lightSourceCount = 0;

        public:
            ShadowNode(ore::GameWorld* world)
                : ore::scene::ContainerNode("Shadow Node"),
                  depthPassShaderNode (world->resourceCache.shaders.getResource_Blocking("shadowDepthPassShader")->getInstance()),
                  shadowShaderNode (world->resourceCache.shaders.getResource_Blocking("shadowRenderShader")->getInstance()){
                for(unsigned int i = 0; i < ore::MAX_SHADOW_LIGHT_SOURCES; i++) {
                    textures.at(i).create(SHADOW_MAP_WIDTH, SHADOW_MAP_HEIGHT);
                    frameBuffers.at(i).create();
                    frameBuffers.at(i).makeShadowMapFramebuffer(textures.at(i));
                }

                // Both render the same scene
                depthPassShaderNode.getChildren()->push_back(&shadowedSceneContentsNode);
                shadowShaderNode.getChildren()->push_back(&shadowedSceneContentsNode);
            }
            void addLight(ore::gl::Light &light);
            void clearLights();

            void render(ore::RenderState &state) override;
            std::vector<SceneNode*>* getChildren() override;
        };
    }
}
