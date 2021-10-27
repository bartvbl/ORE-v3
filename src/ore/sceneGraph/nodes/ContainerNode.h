#pragma once

#include "ore/sceneGraph/SceneNode.h"
#include <string>

namespace ore {
    namespace scene {
        class ContainerNode : public SceneNode {
        public:
            std::vector<SceneNode*> childVector;
            std::string name;

            ContainerNode() : name("Container Node") {}

            explicit ContainerNode(std::string nodeName) : name(nodeName) {}

            std::string getName() override;

            std::vector<SceneNode*> *getChildren() override;

            void destroy();
        };
    }
}


