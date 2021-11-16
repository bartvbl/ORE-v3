#include "Font.h"
#include <ore/gl/shapes/PrimitiveGenerator.h>

void ore::gl::Font::drawText(std::string &text, unsigned int fontSize, glm::vec3 position) {

}

void ore::gl::Font::registerTexture(unsigned int size, ore::resources::Texture texture) {
    textureMap[size] = texture;
}

void ore::gl::Font::init() {
    renderBuffer = ore::gl::PrimitiveGenerator::generatePlaneBuffer().buffer;
}

