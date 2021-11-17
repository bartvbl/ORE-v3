#include "Font.h"
#include <ore/gl/shapes/PrimitiveGenerator.h>
#include <g3log/g3log.hpp>
#include <ore/resources/resourceTypes/mesh/MeshGeometry.h>
#include <ore/gl/vao/GeometryBufferGenerator.h>

ore::gl::GeometryBuffer ore::gl::Font::createRenderableText(std::string &text, unsigned int fontSize) {
    ore::resources::MeshGeometry geometry;
    geometry.hasTextures = true;
    geometry.vertices.resize(4 * text.size());
    geometry.textureCoordinates.resize(4 * text.size());
    geometry.indices.resize(6 * text.size());

    auto characterList = characterMap->find(fontSize);
    if(characterList == characterMap->end()) {
        LOG(FATAL) << "This character map does not contain the size " << fontSize << std::endl;
    }

    float baseXCoordinate = 0;
    unsigned int characterIndex = 0;
    for(char characterInText : text) {
        FontCharacter characterInfo = characterList->second.at((unsigned int) characterInText);

        float positionX = baseXCoordinate + characterInfo.bearingPixels.x;
        float positionY = characterInfo.bearingPixels.y - characterInfo.sizePixels.y;
        float width = characterInfo.sizePixels.x;
        float height = characterInfo.sizePixels.y;

        geometry.vertices.at(4 * characterIndex + 0) = {positionX, positionY, 0};
        geometry.vertices.at(4 * characterIndex + 1) = {positionX + width, positionY, 0};
        geometry.vertices.at(4 * characterIndex + 2) = {positionX + width, positionY + height, 0};
        geometry.vertices.at(4 * characterIndex + 3) = {positionX, positionY + height, 0};

        geometry.textureCoordinates.at(4 * characterIndex + 0) = characterInfo.textureCoordinatesBottomLeft;
        geometry.textureCoordinates.at(4 * characterIndex + 1) = {characterInfo.textureCoordinatesTopRight.x,
                                                                  characterInfo.textureCoordinatesBottomLeft.y};
        geometry.textureCoordinates.at(4 * characterIndex + 2) = characterInfo.textureCoordinatesTopRight;
        geometry.textureCoordinates.at(4 * characterIndex + 3) = {characterInfo.textureCoordinatesBottomLeft.x,
                                                                  characterInfo.textureCoordinatesTopRight.y};

        geometry.indices.at(6 * characterIndex + 0) = 4 * characterIndex + 0;
        geometry.indices.at(6 * characterIndex + 1) = 4 * characterIndex + 1;
        geometry.indices.at(6 * characterIndex + 2) = 4 * characterIndex + 2;
        geometry.indices.at(6 * characterIndex + 3) = 4 * characterIndex + 0;
        geometry.indices.at(6 * characterIndex + 4) = 4 * characterIndex + 2;
        geometry.indices.at(6 * characterIndex + 5) = 4 * characterIndex + 3;

        baseXCoordinate += characterInfo.advancePixels;
        characterIndex++;
    }

    return ore::gl::generateGeometryBuffer(geometry);
}

