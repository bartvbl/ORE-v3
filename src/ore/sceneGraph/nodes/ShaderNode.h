#pragma once

#include "ContainerNode.h"

namespace ore {
    namespace scene {
        class ShaderNode : public ore::scene::ContainerNode {
        public:
            ShaderNode() : ore::scene::ContainerNode("Shader Node") {}
            void preRender(RenderState &renderState);
            void render(RenderState &renderState);
            void postRender(RenderState &renderState);
        };
    }
}