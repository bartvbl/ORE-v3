#pragma once

#include <ore/gl/render/RenderState.h>
#include <ore/gl/vao/GeometryBuffer.h>
#include <ore/gl/render/RenderMode.h>
#include <filesystem>
#include "CoordinateNode.h"

namespace ore {
    namespace scene {
        class VideoTextureNode : public ore::scene::CoordinateNode {
        public:
            explicit VideoTextureNode(std::filesystem::path videoFile);
            void preRender(RenderState &state) override;
            void render(RenderState &renderState) override;
        };
    }
}