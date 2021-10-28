#pragma once

#include "ContainerNode.h"

namespace ore {
    namespace scene {
        class ShaderNode : public ore::scene::ContainerNode {
        public:
            ShaderNode() : ore::scene::ContainerNode("Shader Node") {}
            void render(RenderState &renderState);
        };
    }
}