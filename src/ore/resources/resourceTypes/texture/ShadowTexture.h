#pragma once

#include <ore/resources/resourceTypes/texture/Texture.h>

namespace ore {
    namespace resources {
        class ShadowTexture : public ore::resources::Texture {

        public:
            void create(unsigned int width, unsigned int height);
        };
    }
}