#pragma once

#include <ore/sceneGraph/nodes/ContainerNode.h>
#include <ore/sceneGraph/nodes/ShaderNode.h>
#include <ore/gl/frameBuffer/FrameBuffer.h>
#include <ore/gl/lighting/Light.h>
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
            ShadowNode() : ore::scene::ContainerNode("Shadow Node") {
                texture.create(SHADOW_MAP_WIDTH, SHADOW_MAP_HEIGHT);
                frameBuffer.create();
                frameBuffer.makeShadowMapFramebuffer(texture);

                // Both render the same scene
                depthPassShaderNode.getChildren()->push_back(&shadowedSceneContentsNode);
                shadowShaderNode.getChildren()->push_back(&shadowedSceneContentsNode);
            }

            void setLightSource(ore::gl::Light lightSource);
            void render(ore::RenderState &state) override;
            std::vector<SceneNode*>* getChildren() override;
        };
    }
}
