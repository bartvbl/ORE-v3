#pragma once
#include <ore/sceneGraph/SceneNode.h>

namespace ore {
    class MeshNode : ore::SceneNode {
        std::string getName();

        std::vector<SceneNode*>* getChildren();

        void destroy();
    };
}
