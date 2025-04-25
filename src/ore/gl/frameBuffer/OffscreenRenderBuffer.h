#pragma once
#include <ore/resources/resourceTypes/texture/ShadowTexture.h>
#include "ore/gl/render/RenderState.h"

namespace ore {
    namespace gl {
        struct OffscreenRenderBuffer {
            uint32_t id = 0;
            uint32_t renderBufferID = 0;
            uint32_t width = 0;
            uint32_t height = 0;
            ore::resources::Texture colourTexture;
            ore::resources::Texture depthTexture;

            void create(int32_t widthPixels, int32_t heightPixels);
            void activate(bool clear = true);
            void deactivate();
            void render(ore::RenderState& renderState);
            void blitAt(uint32_t x, uint32_t y);
        };
    }
}