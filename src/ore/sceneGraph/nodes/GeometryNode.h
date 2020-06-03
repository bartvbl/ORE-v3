#pragma once

#include <ore/gl/render/RenderState.h>
#include <ore/gl/vao/GeometryBuffer.h>
#include "CoordinateNode.h"

namespace ore {
    namespace scene {
        class GeometryNode : public ore::scene::CoordinateNode {
        private:
            glm::mat4 modelMatrix = glm::mat4(1.0);
            ore::gl::GeometryBuffer buffer;
        public:
            GeometryNode() : ore::scene::CoordinateNode("Geometry Node") {}
            GeometryNode(ore::gl::GeometryBuffer buffer) : ore::scene::CoordinateNode("Geometry Node"), buffer(buffer) {}

            void preUpdate(RenderState &renderState) override;
            void postUpdate(RenderState &renderState) override;

            void preRender(RenderState &renderState) override;
            void render(RenderState &renderState) override;
            void postRender(RenderState &renderState) override;
        };
    }
}