#pragma once

namespace ore {
    namespace resources {
        struct Texture {
            unsigned int id = 0;
            unsigned int widthPixels = 0;
            unsigned int heightPixels = 0;

            Texture(unsigned int textureID, unsigned int width, unsigned int height) : id(textureID), widthPixels(width), heightPixels(height) {}
            Texture() = default;
        };
    }
}