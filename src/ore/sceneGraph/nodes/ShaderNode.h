#pragma once

#include "ContainerNode.h"
#include <ore/resources/resourceTypes/shader/Shader.h>

namespace ore {
    namespace scene {
        class ShaderNode : public ore::scene::ContainerNode {
        private:
            ore::resources::Shader shader;
            bool isShaderSet = false;
        public:
            ShaderNode() : ore::scene::ContainerNode("Shader Node") {}
            ShaderNode(ore::resources::Shader shader) : shader(shader) {
                isShaderSet = true;
            }
            void render(RenderState &renderState);
        };
    }
}