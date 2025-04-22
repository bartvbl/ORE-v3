#pragma once

#include <ore/resources/resourceTypes/texture/Texture.h>

namespace ore {
    namespace gl {
        ore::resources::Texture generateTexture(const unsigned char* imageDataRGBA, unsigned int width, unsigned int height);
        ore::resources::Texture generateEmptyTexture(uint32_t width, uint32_t height);
    }
}