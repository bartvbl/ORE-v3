#pragma once
#include <ore/sceneGraph/nodes/GeometryNode.h>

namespace ore {
    namespace gl {
        namespace PrimitiveGenerator {
            ore::scene::GeometryNode generatePlaneBuffer(glm::vec2 bottomLeft = {0, 0}, glm::vec2 topRight = {1, 1});
        };
    }
}