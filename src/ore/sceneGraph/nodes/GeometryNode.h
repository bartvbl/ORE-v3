#pragma once

#include <ore/gl/render/RenderState.h>
#include <ore/gl/vao/GeometryBuffer.h>
#include "CoordinateNode.h"

namespace ore {
    namespace scene {
        class GeometryNode : public ore::scene::CoordinateNode {
        private:
            ore::gl::GeometryBuffer buffer;
            unsigned int startIndex = 0;
            unsigned int indexCount = 0;
        public:
            GeometryNode() : ore::scene::CoordinateNode("Geometry Node") {}
            GeometryNode(ore::gl::GeometryBuffer buffer, unsigned int startIndex = 0, unsigned int indexCount = 0)
                : ore::scene::CoordinateNode("Geometry Node"),
                  buffer(buffer), startIndex(startIndex), indexCount(indexCount) {
                if(indexCount == 0) {
                    this->indexCount = buffer.indexCount;
                }
            }

            void render(RenderState &renderState);
        };
    }
}