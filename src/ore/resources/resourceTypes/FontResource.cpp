#include "FontResource.h"
#include <ft2build.h>
#include <glad/glad.h>
#include <ore/gl/texture/TextureGenerator.h>
#include <iostream>
#include <array>
#include FT_FREETYPE_H

const unsigned int CHARACTER_PADDING_PIXELS = 2;
const std::array<unsigned int, 9> CHARACTER_SIZES = {8, 9, 10, 11, 12, 18, 32, 48, 96};
const unsigned int CHAR_COUNT_TO_LOAD = 128;
const std::array<unsigned int, 6> specialCharacters = {
        0xE5, 0xE6, 0xF8, 0xD8, 0xC5, 0xC6
};

void computeTextureDimensions(FT_Face &face, unsigned int &textureWidth, unsigned int &textureHeight, const ore::filesystem::path &fileLocation) {
    textureWidth = 0;
    textureHeight = 0;

    for (unsigned int c = 0; c < CHAR_COUNT_TO_LOAD; c++) {
        // Load character glyph
        if (FT_Load_Char(face, c, FT_LOAD_RENDER)) {
            LOG(FATAL) << "Failed to load font from " + fileLocation.string() + ": Could not create the character '" +
                          (char) c + "'" << std::endl;
        }

        textureWidth += face->glyph->bitmap.width + CHARACTER_PADDING_PIXELS;
        textureHeight = std::max<unsigned int>(textureHeight, face->glyph->bitmap.rows);
    }

    for (unsigned int specialCharacter : specialCharacters) {
        // Load character glyph
        if (FT_Load_Char(face, specialCharacter, FT_LOAD_RENDER)) {
            LOG(FATAL) << "Failed to load font from " + fileLocation.string() + ": Could not create the character '" <<
                        specialCharacter << "'" << std::endl;
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

    std::array<unsigned int, CHARACTER_SIZES.size()> rowHeights = {0, 0, 0, 0, 0, 0, 0};
    unsigned int rowIndex = 0;

    // Determine texture dimensions
    for(unsigned int size : CHARACTER_SIZES) {
        FT_Set_Pixel_Sizes(face, 0, size);
        unsigned int textureWidth = 0;
        unsigned int textureHeight = 0;
        computeTextureDimensions(face, textureWidth, textureHeight, fileLocation);
        totalTextureWidth = std::max<unsigned int>(totalTextureWidth, textureWidth);
        totalTextureHeight += textureHeight + CHARACTER_PADDING_PIXELS;
        rowHeights.at(rowIndex) = textureHeight;
        rowIndex++;
    }

    // Allocate texture
    characterTextureDataRGBA.resize(sizeof(unsigned int) * totalTextureWidth * totalTextureHeight);
    std::fill(characterTextureDataRGBA.begin(), characterTextureDataRGBA.end(), 0);
    fontTextureWidthPixels = totalTextureWidth;
    fontTextureHeightPixels = totalTextureHeight;

    // Copy glyphs into texture
    rowIndex = 0;
    unsigned int baseYCoordinate = 0;
    for(unsigned int fontSize : CHARACTER_SIZES) {
        FT_Set_Pixel_Sizes(face, 0, fontSize);
        unsigned int baseXCoordinate = 0;
        for(unsigned int charIndex = 0; charIndex < CHAR_COUNT_TO_LOAD; charIndex++) {
            // Load character glyph
            if (FT_Load_Char(face, charIndex, FT_LOAD_RENDER)) {
                LOG(FATAL) << "Failed to load font from " + fileLocation.string() + ": Could not create the character '" +
                              (char) charIndex + "'" << std::endl;
            }

            for(unsigned int y = 0; y < face->glyph->bitmap.rows; y++) {
                for(unsigned int x = 0; x < face->glyph->bitmap.width; x++) {
                    unsigned char pixelValue = face->glyph->bitmap.buffer[(y * face->glyph->bitmap.width) + x];

                    unsigned int pixelXCoordinate = baseXCoordinate + x;
                    unsigned int pixelYCoordinate = baseYCoordinate + face->glyph->bitmap.rows - 1 - y;
                    unsigned int pixelIndex = totalTextureWidth * pixelYCoordinate + pixelXCoordinate;
                    unsigned int arrayIndex = sizeof(unsigned int) * pixelIndex;

                    // Set alpha channel
                    characterTextureDataRGBA.at(arrayIndex + 0) = pixelValue;
                    characterTextureDataRGBA.at(arrayIndex + 1) = pixelValue;
                    characterTextureDataRGBA.at(arrayIndex + 2) = pixelValue;
                    characterTextureDataRGBA.at(arrayIndex + 3) = pixelValue;
                }
            }

            ore::gl::FontCharacter character;
            character.textureCoordinatesBottomLeft = glm::vec2(float(baseXCoordinate) / float(totalTextureWidth),
                                                               float(baseYCoordinate) / float(totalTextureHeight));
            character.textureCoordinatesTopRight = glm::vec2(float(baseXCoordinate + face->glyph->bitmap.width) / float(totalTextureWidth),
                                                             float(baseYCoordinate + face->glyph->bitmap.rows) / float(totalTextureHeight));
            character.bearingPixels = glm::vec2(float(face->glyph->bitmap_left),float(face->glyph->bitmap_top));
            character.sizePixels = glm::vec2(face->glyph->bitmap.width, face->glyph->bitmap.rows);
            // Advance is given in 1/64th pixel, so we scale it to be measured in pixels.
            character.advancePixels = float(static_cast<unsigned int>(face->glyph->advance.x)) / 64.0f;
            characterMap[fontSize].push_back(character);

            baseXCoordinate += face->glyph->bitmap.width + CHARACTER_PADDING_PIXELS;
        }

        for (unsigned int specialCharacter : specialCharacters) {
            // Load character glyph
            if (FT_Load_Char(face, specialCharacter, FT_LOAD_RENDER)) {
                LOG(FATAL) << "Failed to load font from " + fileLocation.string() + ": Could not create the character '" <<
                           specialCharacter << "'" << std::endl;
            }

            for(unsigned int y = 0; y < face->glyph->bitmap.rows; y++) {
                for(unsigned int x = 0; x < face->glyph->bitmap.width; x++) {
                    unsigned char pixelValue = face->glyph->bitmap.buffer[(y * face->glyph->bitmap.width) + x];

                    unsigned int pixelXCoordinate = baseXCoordinate + x;
                    unsigned int pixelYCoordinate = baseYCoordinate + face->glyph->bitmap.rows - 1 - y;
                    unsigned int pixelIndex = totalTextureWidth * pixelYCoordinate + pixelXCoordinate;
                    unsigned int arrayIndex = sizeof(unsigned int) * pixelIndex;

                    // Set alpha channel
                    characterTextureDataRGBA.at(arrayIndex + 0) = pixelValue;
                    characterTextureDataRGBA.at(arrayIndex + 1) = pixelValue;
                    characterTextureDataRGBA.at(arrayIndex + 2) = pixelValue;
                    characterTextureDataRGBA.at(arrayIndex + 3) = pixelValue;
                }
            }

            ore::gl::FontCharacter character;
            character.textureCoordinatesBottomLeft = glm::vec2(float(baseXCoordinate) / float(totalTextureWidth),
                                                               float(baseYCoordinate) / float(totalTextureHeight));
            character.textureCoordinatesTopRight = glm::vec2(float(baseXCoordinate + face->glyph->bitmap.width) / float(totalTextureWidth),
                                                             float(baseYCoordinate + face->glyph->bitmap.rows) / float(totalTextureHeight));
            character.bearingPixels = glm::vec2(float(face->glyph->bitmap_left),float(face->glyph->bitmap_top));
            character.sizePixels = glm::vec2(face->glyph->bitmap.width, face->glyph->bitmap.rows);
            // Advance is given in 1/64th pixel, so we scale it to be measured in pixels.
            character.advancePixels = float(static_cast<unsigned int>(face->glyph->advance.x)) / 64.0f;
            characterMap[fontSize].push_back(character);

            baseXCoordinate += face->glyph->bitmap.width + CHARACTER_PADDING_PIXELS;
        }



        baseYCoordinate += rowHeights.at(rowIndex) + CHARACTER_PADDING_PIXELS;
        rowIndex++;
    }

        /*
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
        Character character = {
                texture,
                glm::ivec2(face->glyph->bitmap.width, face->glyph->bitmap.rows),
                glm::ivec2(face->glyph->bitmap_left, face->glyph->bitmap_top),
                static_cast<unsigned int>(face->glyph->advance.x)
        };*/
    FT_Done_Face(face);
    FT_Done_FreeType(ft);
}

bool ore::resources::FontResource::requiresMainThread() {
    return true;
}

void ore::resources::FontResource::completeLoadOnMainThread() {
    ore::resources::Texture texture = ore::gl::generateTexture(characterTextureDataRGBA.data(), fontTextureWidthPixels, fontTextureHeightPixels);
    font = new ore::gl::Font(texture, &characterMap);
}

void ore::resources::FontResource::destroy() {

}

ore::scene::TextNode ore::resources::FontResource::getInstance() {
    return ore::scene::TextNode(font);
}
