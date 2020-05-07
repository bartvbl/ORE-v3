#pragma once

#include "SceneNode.h"
#include <string>

namespace ore {
    class ContainerNode : public SceneNode {
    private:
        std::vector<SceneNode> childVector;
    public:
        std::string name;

        ContainerNode() : name("Container Node") {}

        ContainerNode(std::string nodeName) : name(nodeName) {}

        void preRender(RenderState &renderState) override;
        void render(RenderState &renderState) override;
        void postRender(RenderState &renderState) override;

        std::vector<SceneNode> *getChildren() override;

        void destroy() override;
    };
}


