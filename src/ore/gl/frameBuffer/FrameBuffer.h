#pragma once
#include <ore/resources/resourceTypes/texture/ShadowTexture.h>
#include "ore/gl/render/RenderState.h"

namespace ore {
    namespace gl {
        struct FrameBuffer {
            uint32_t id = 0;
            ore::resources::Texture colourTexture;

            void create();
            void activate();
            void deactivate(WindowDimensionsRenderState windowState);
            void makeShadowMapFramebuffer(ore::resources::ShadowTexture texture);
            void makeOffscreenRenderFrameBuffer(uint32_t widthPixels, uint32_t heightPixels);
        };
    }
}