#pragma once
#include <string>
#include <glm/glm.hpp>
#include <ore/resources/resourceTypes/texture/Texture.h>
#include <unordered_map>
#include <ore/gl/vao/GeometryBuffer.h>

namespace ore {
    namespace gl {
        class Font {
        private:
            std::unordered_map<unsigned int, ore::resources::Texture> textureMap;
            ore::gl::GeometryBuffer renderBuffer;
        public:
            explicit Font() = default;
            void init();
            void registerTexture(unsigned int size, ore::resources::Texture texture);
            void drawText(std::string &text, unsigned int fontSize = 16, glm::vec3 position = {0, 0, 0});
        };
    }
}