#pragma once


#include "ContainerNode.h"

namespace ore {
    namespace scene {
        class OrthographicCamera : public ore::scene::ContainerNode {
        public:
            float left = 0;
            float right = 1;
            float bottom = 0;
            float top = 1;
            float zNear = 0;
            float zFar = 1;

            OrthographicCamera() : ore::scene::ContainerNode("Orthographic Camera") {}

            void render(RenderState &renderState);
        };
    }
}

