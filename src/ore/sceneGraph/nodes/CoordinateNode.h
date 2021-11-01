#pragma once

#include <ore/geom/vec3.h>
#include "ContainerNode.h"
#include <glm/glm.hpp>

namespace ore {
    namespace scene {
        class CoordinateNode : public ore::scene::ContainerNode {
        public:
            ore::geom::vec3 position = {0, 0, 0};
            ore::geom::vec3 rotation = {0, 0, 0};
            ore::geom::vec3 scale = {1, 1, 1};
            ore::geom::vec3 pivot = {0, 0, 0};

            glm::mat4 storedModelMatrix;

            CoordinateNode(std::string nodeName) : ore::scene::ContainerNode(nodeName) {}
            CoordinateNode() : ore::scene::ContainerNode("Coordinate Node") {}

            void preRender(RenderState &renderState) override;
            void render(RenderState &renderState) override;
            void postRender(RenderState &renderState) override;
            std::string getName();
        };
    }
}