#pragma once

#include <ore/sceneGraph/nodes/CoordinateNode.h>

#include <utility>

namespace ore {
    namespace scene {
        class PositionNode : public ore::scene::CoordinateNode {
        public:
            explicit PositionNode(std::string name) : CoordinateNode(std::move(name)) {}
            PositionNode() = default;

            void render(ore::RenderState &state) override;
        };
    }
}