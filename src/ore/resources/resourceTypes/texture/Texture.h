#pragma once

namespace ore {
    namespace resources {
        struct Texture {
            unsigned int id = 0;

            Texture(unsigned int textureID) : id(textureID) {}
            Texture() = default;
        };
    }
}