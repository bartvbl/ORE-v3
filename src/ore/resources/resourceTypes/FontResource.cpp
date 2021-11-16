#include "FontResource.h"
#include <ft2build.h>
#include <glad/glad.h>
#include <iostream>
#include <array>
#include FT_FREETYPE_H

const unsigned int CHARACTER_PADDING_PIXELS = 2;
const std::array<unsigned int, 7> CHARACTER_SIZES = {8, 9, 10, 11, 12, 18, 48};

void computeTextureDimensions(FT_Face &face, unsigned int &textureWidth, unsigned int &textureHeight, const ore::filesystem::path &fileLocation) {
    textureWidth = 0;
    textureHeight = 0;
    unsigned int charCountToLoad = 128;
    for (unsigned char c = 0; c < charCountToLoad; c++) {
        // Load character glyph
        if (FT_Load_Char(face, c, FT_LOAD_RENDER)) {
            LOG(FATAL) << "Failed to load font from " + fileLocation.string() + ": Could not create the character '" +
                          (char) c + "'" << std::endl;
        }
        textureWidth += face->glyph->bitmap.width + CHARACTER_PADDING_PIXELS;
        textureHeight = std::max<unsigned int>(textureHeight, face->glyph->bitmap.rows);
    }
}

void ore::resources::FontResource::load(const ore::filesystem::path &fileLocation) {
    FT_Library ft;

    if(FT_Init_FreeType(&ft))
    {
        LOG(FATAL) << "Failed to load font from " + fileLocation.string() + ": Could not initialise the FreeType library" << std::endl;
    }

    FT_Face face;
    FT_New_Face(ft, fileLocation.string().c_str(), 0, &face);


    unsigned int totalTextureWidth = 0;
    unsigned int totalTextureHeight = 0;

    for(unsigned int size : CHARACTER_SIZES) {
        FT_Set_Pixel_Sizes(face, 0, size);
        unsigned int textureWidth = 0;
        unsigned int textureHeight = 0;
        computeTextureDimensions(face, textureWidth, textureHeight, fileLocation);
        std::cout << "Size " << size << " requires " << textureWidth << "x" << textureHeight << std::endl;
    }

    characterTextureData.resize(totalTextureWidth * totalTextureHeight);

    //std::cout << "Character texture map is " << textureWidth << "x" << textureHeight << std::endl;

        /*unsigned int texture;
        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);
        glTexImage2D(
                GL_TEXTURE_2D,
                0,
                GL_RED,
                face->glyph->bitmap.width,
                face->glyph->bitmap.rows,
                0,
                GL_RED,
                GL_UNSIGNED_BYTE,
                face->glyph->bitmap.buffer
        );
        // set texture options
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        // now store character for later use
        Character character = {
                texture,
                glm::ivec2(face->glyph->bitmap.width, face->glyph->bitmap.rows),
                glm::ivec2(face->glyph->bitmap_left, face->glyph->bitmap_top),
                static_cast<unsigned int>(face->glyph->advance.x)
        };
        Characters.insert(std::pair<char, Character>(c, character));
    }
    glBindTexture(GL_TEXTURE_2D, 0);*/
    // destroy FreeType once we're finished
    FT_Done_Face(face);
    FT_Done_FreeType(ft);
}

bool ore::resources::FontResource::requiresMainThread() {
    return true;
}

void ore::resources::FontResource::completeLoadOnMainThread() {



}

void ore::resources::FontResource::destroy() {

}

ore::scene::TextNode ore::resources::FontResource::getInstance() {
    return ore::scene::TextNode(ore::gl::Font());
}
