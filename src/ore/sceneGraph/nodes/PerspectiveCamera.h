#pragma once


#include "CoordinateNode.h"

namespace ore {
    namespace scene {
        class PerspectiveCamera : public ore::scene::CoordinateNode {
        public:
            float fovY = 90;
            float zNear = 0.1;
            float zFar = 100.0;

            PerspectiveCamera() : ore::scene::CoordinateNode("Perspective Camera") {}

            void render(RenderState &renderState) override;
        };
    }
}