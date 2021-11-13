#pragma once
#include <ore/resources/resourceTypes/texture/ShadowTexture.h>

namespace ore {
    namespace gl {
        struct FrameBuffer {
            unsigned int id = 0;

            void create();
            void makeShadowMapFramebuffer(ore::resources::ShadowTexture texture) const;
        };
    }
}