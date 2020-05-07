#pragma once

#include "SceneNode.h"
#include <string>

namespace ore {
    class ContainerNode : public SceneNode {
    public:
        std::vector<SceneNode> childVector;
        std::string name;

        ContainerNode() : name("Container Node") {}

        ContainerNode(std::string nodeName) : name(nodeName) {}

        std::string getName() override;

        void preRender(RenderState &renderState) override;
        void render(RenderState &renderState) override;
        void postRender(RenderState &renderState) override;

        std::vector<SceneNode> *getChildren() override;

        void destroy() override;
    };
}


