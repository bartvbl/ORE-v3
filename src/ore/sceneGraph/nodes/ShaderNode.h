#pragma once

#include "ContainerNode.h"

namespace ore {
    namespace scene {
        class ShaderNode : public ore::scene::ContainerNode {
        public:
            ShaderNode() : ore::scene::ContainerNode("Shader Node") {}
            void preRender(RenderState &renderState) override;
            void render(RenderState &renderState) override;
            void postRender(RenderState &renderState) override;
        };
    }
}