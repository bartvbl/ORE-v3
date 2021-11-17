#pragma once
#include <string>
#include <utility>
#include <vector>
#include <glm/glm.hpp>
#include <ore/resources/resourceTypes/texture/Texture.h>
#include <unordered_map>
#include <ore/gl/vao/GeometryBuffer.h>
#include <ore/gl/font/FontCharacter.h>

namespace ore {
    namespace gl {
        class Font {
        private:
            std::unordered_map<unsigned int, std::vector<ore::gl::FontCharacter>>* characterMap = nullptr;
        public:
            ore::resources::Texture textureMap;

            explicit Font(ore::resources::Texture texture, std::unordered_map<unsigned int, std::vector<ore::gl::FontCharacter>>* characterMap) : characterMap(characterMap), textureMap(texture) {};
            ore::gl::GeometryBuffer createRenderableText(std::string &text, unsigned int fontSize = 16);
        };
    }
}