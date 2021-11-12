#pragma once


#include "CoordinateNode.h"

namespace ore {
    namespace scene {
        class OrthographicCamera : public ore::scene::CoordinateNode {
        public:
            float left = 0;
            float right = 1;
            float bottom = 0;
            float top = 1;
            float zNear = 0;
            float zFar = 1;

            bool depthTestingEnabled = true;

            OrthographicCamera() : ore::scene::CoordinateNode("Orthographic Camera") {}

            void render(RenderState &renderState);

            void setBounds(float _left, float _right, float _bottom, float _top, float _near, float _far);

            void setDepthTestingEnabled(bool enabled);
        };
    }
}

