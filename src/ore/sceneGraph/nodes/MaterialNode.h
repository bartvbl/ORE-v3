#pragma once

#include <ore/sceneGraph/nodes/ContainerNode.h>

namespace ore {
    namespace scene {
    class MaterialNode : public ore::scene::ContainerNode {
    public:
        MaterialNode() : ore::scene::ContainerNode("Material Node") {}

        void preRender(RenderState &renderState) override;

        void render(RenderState &renderState) override;

        void postRender(RenderState &renderState) override;
    };
    }
}