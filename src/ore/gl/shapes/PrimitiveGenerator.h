#pragma once
#include <ore/sceneGraph/nodes/GeometryNode.h>

namespace ore {
    namespace gl {
        namespace PrimitiveGenerator {
            ore::scene::GeometryNode generatePlaneBuffer(glm::vec2 bottomLeft = {0, 0}, glm::vec2 topRight = {1, 1});
            ore::scene::GeometryNode generateCircleBuffer(glm::vec2 center = {0, 0}, float radius = 1, uint32_t sliceCount = 45);
        };
    }
}