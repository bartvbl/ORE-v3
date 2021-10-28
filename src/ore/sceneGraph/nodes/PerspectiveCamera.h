#pragma once


#include "ContainerNode.h"

namespace ore {
    namespace scene {
        class PerspectiveCamera : public ore::scene::ContainerNode {
        public:
            float fovY = 90;
            float zNear = 0.01;
            float zFar = 1000.0;

            glm::vec3 position = {0, 0, 0};
            glm::vec3 rotation = {0, 0, 0};

            PerspectiveCamera() : ore::scene::ContainerNode("Perspective Camera") {}

            void render(RenderState &renderState);
        };
    }
}