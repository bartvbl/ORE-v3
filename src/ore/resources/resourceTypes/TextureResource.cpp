#include <iostream>
#include <ore/gl/texture/TextureGenerator.h>
#include "TextureResource.h"
#include "stb_image.h"
#include <glad/glad.h>

void ore::resources::TextureResource::load(const ore::filesystem::path &fileLocation) {
    if(!ore::filesystem::exists(fileLocation)) {
        LOG(FATAL) << "The texture file at " << fileLocation.string() << " was not found." << std::endl;
    }

    imageData = stbi_load(fileLocation.string().c_str(), &imageWidth, &imageHeight, &channelCount, 4);

    // Unfortunately, images usually have their origin at the top left.
    // OpenGL instead defines the origin to be on the _bottom_ left instead, so
    // here's the world's most inefficient way to flip the image vertically.

    unsigned int widthBytes = 4 * imageWidth;

    for(unsigned int row = 0; row < (imageHeight / 2); row++) {
        for(unsigned int col = 0; col < widthBytes; col++) {
            std::swap(imageData[row * widthBytes + col], imageData[(imageHeight - 1 - row) * widthBytes + col]);
        }
    }

    textureIsLoaded = true;
}

void ore::resources::TextureResource::load(ore::resources::Texture alreadyLoadedTexture) {
    this->texture = alreadyLoadedTexture;
    textureIsLoaded = true;
}

bool ore::resources::TextureResource::requiresMainThread() {
    return true;
}

void ore::resources::TextureResource::completeLoadOnMainThread() {
    texture = ore::gl::generateTexture(imageData, imageWidth, imageHeight);
    stbi_image_free(imageData);
}

void ore::resources::TextureResource::destroy() {
    if(textureIsLoaded) {
        glDeleteTextures(1, &texture.id);
    }
}

bool ore::resources::TextureResource::isLoaded() {
    return textureIsLoaded;
}

ore::resources::Texture ore::resources::TextureResource::getInstance() {
    return texture;
}


