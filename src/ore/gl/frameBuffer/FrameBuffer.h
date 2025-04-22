#pragma once
#include <ore/resources/resourceTypes/texture/ShadowTexture.h>
#include "ore/gl/render/RenderState.h"

namespace ore {
    namespace gl {
        struct FrameBuffer {
            uint32_t id = 0;
            ore::resources::Texture colourTexture;
            ore::resources::Texture depthTexture;

            void create();
            void activate();
            void deactivate(WindowDimensionsRenderState windowState);
            void makeShadowMapFramebuffer(ore::resources::ShadowTexture texture);
            void makeOffscreenRenderFrameBuffer(ore::resources::Texture texture);
        };
    }
}