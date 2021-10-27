#pragma once
#include <ore/sceneGraph/SceneNode.h>
#include "CoordinateNode.h"
#include "MaterialNode.h"
#include <ore/sceneGraph/nodes/GeometryNode.h>

namespace ore {
    class MeshNode : public ore::scene::CoordinateNode {
    public:
        // The notes stored in the vectors use pointers.
        // These may be invalidated by copying or modification

        std::string name;
        std::string meshResourceName;
        std::vector<ore::scene::GeometryNode> geometryNodes;
        std::vector<ore::scene::MaterialNode> materialNodes;
        std::vector<ore::scene::CoordinateNode> intermediateNodes;

        MeshNode(std::string &name) : name(name) {}

        std::string getName();

        void destroy();
    };
}
