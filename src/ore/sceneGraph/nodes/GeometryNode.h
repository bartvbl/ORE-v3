#pragma once

#include <ore/gl/render/RenderState.h>
#include "CoordinateNode.h"

namespace ore {
    namespace scene {
        class GeometryNode : public ore::scene::CoordinateNode {
        private:
            glm::mat4 modelMatrix;
        public:
            GeometryNode() : ore::scene::CoordinateNode("Geometry Node") {}

            void preUpdate(RenderState &renderState) override;
            void postUpdate(RenderState &renderState) override;

            void preRender(RenderState &renderState) override;
            void render(RenderState &renderState) override;
            void postRender(RenderState &renderState) override;
        };
    }
}