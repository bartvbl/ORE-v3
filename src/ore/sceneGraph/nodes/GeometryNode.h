#pragma once

#include <ore/gl/render/RenderState.h>
#include <ore/gl/vao/GeometryBuffer.h>
#include <ore/gl/render/RenderMode.h>
#include "CoordinateNode.h"

namespace ore {
    namespace scene {
        class GeometryNode : public ore::scene::CoordinateNode {
        public:
            ore::gl::GeometryBuffer buffer;
            unsigned int startIndex = 0;
            unsigned int indexCount = 0;
            ore::gl::RenderMode mode = ore::gl::RenderMode::TRIANGLES;

            GeometryNode(std::string name = "Geometry Node") : ore::scene::CoordinateNode(std::move(name)) {}
            GeometryNode(ore::gl::GeometryBuffer buffer, unsigned int startIndex = 0, unsigned int indexCount = 0)
                : ore::scene::CoordinateNode("Geometry Node"),
                  buffer(buffer), startIndex(startIndex), indexCount(indexCount) {
                if(indexCount == 0) {
                    this->indexCount = buffer.indexCount;
                }
            }

            void preRender(RenderState &state) override;
            void render(RenderState &renderState) override;
            void drawBuffer() const;
            void destroyGeometryBuffer();
            void setRenderMode(ore::gl::RenderMode mode);
        };
    }
}