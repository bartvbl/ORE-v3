#pragma once

#include <ore/sceneGraph/nodes/ContainerNode.h>
#include <ore/sceneGraph/nodes/ShaderNode.h>
#include <ore/gl/frameBuffer/FrameBuffer.h>
#include <ore/gl/lighting/Light.h>
#include <ore/world/GameWorld.h>
#include <ore/resources/resourceTypes/texture/ShadowTexture.h>

namespace ore {
    namespace scene {
        class ShadowNode : public ore::scene::ContainerNode {
        private:
            const unsigned int SHADOW_MAP_WIDTH = 2048;
            const unsigned int SHADOW_MAP_HEIGHT = 2048;
            ore::scene::ShaderNode depthPassShaderNode;
            ore::scene::ShaderNode shadowShaderNode;
            ore::scene::ContainerNode shadowedSceneContentsNode;
            ore::gl::FrameBuffer frameBuffer;
            ore::gl::Light lightSource;
            ore::resources::ShadowTexture texture;
        public:
            ShadowNode(ore::GameWorld* world)
                : ore::scene::ContainerNode("Shadow Node"),
                  depthPassShaderNode (world->resourceCache.shaders.getResource_Blocking("shadowDepthPassShader")->getInstance()),
                  shadowShaderNode (world->resourceCache.shaders.getResource_Blocking("shadowRenderShader")->getInstance()){
                texture.create(SHADOW_MAP_WIDTH, SHADOW_MAP_HEIGHT);
                frameBuffer.create();
                frameBuffer.makeShadowMapFramebuffer(texture);

                // Both render the same scene
                depthPassShaderNode.getChildren()->push_back(&shadowedSceneContentsNode);
                shadowShaderNode.getChildren()->push_back(&shadowedSceneContentsNode);
            }

            void setLightSource(ore::gl::Light updatedLightSource);
            void render(ore::RenderState &state) override;
            std::vector<SceneNode*>* getChildren() override;
        };
    }
}
