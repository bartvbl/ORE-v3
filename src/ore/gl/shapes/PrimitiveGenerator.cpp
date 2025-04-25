#include <ore/resources/resourceTypes/mesh/MeshGeometry.h>
#include <ore/gl/vao/GeometryBufferGenerator.h>
#include "PrimitiveGenerator.h"

ore::scene::GeometryNode ore::gl::PrimitiveGenerator::generatePlaneBuffer(glm::vec2 bottomLeft, glm::vec2 topRight) {
    ore::resources::MeshGeometry geometry;
    geometry.vertices = {
            glm::vec3(bottomLeft.x, bottomLeft.y, 0),
            glm::vec3(topRight.x, bottomLeft.y, 0),
            glm::vec3(topRight.x, topRight.y, 0),
            glm::vec3(bottomLeft.x, topRight.y, 0)};
    geometry.textureCoordinates = {
            glm::vec2(0, 0),
            glm::vec2(1, 0),
            glm::vec2(1, 1),
            glm::vec2(0, 1)
    };
    geometry.hasTextures = true;
    geometry.indices = {0, 1, 2, 0, 2, 3};
    ore::gl::GeometryBuffer planeBuffer = ore::gl::generateGeometryBuffer(geometry);
    return {planeBuffer};
}

ore::scene::GeometryNode ore::gl::PrimitiveGenerator::generateCircleBuffer(glm::vec2 center, float radius, uint32_t sliceCount) {
    ore::resources::MeshGeometry geometry;

    geometry.vertices.resize(sliceCount + 1);
    geometry.indices.resize(3 * sliceCount);
    geometry.hasTextures = false;
    geometry.hasNormals = false;
    geometry.hasNormalMap = false;
    geometry.vertices.at(0) = glm::vec3(center, 0);

    for (uint32_t i = 1; i <= sliceCount; i++) {
        glm::vec2 outerVertex;
        float fraction = float(i) / float(sliceCount);
        float angle = fraction * (M_PI * 2.0f);
        geometry.vertices.at(i) = glm::vec3(center.x + (radius * float(std::cos(angle))),
                                center.y + (radius * float(std::sin(angle))), 0.0f);

        // Main circle index buffer
        geometry.indices.at(3 * (i - 1) + 0) = 0;
        geometry.indices.at(3 * (i - 1) + 1) = i - 1;
        geometry.indices.at(3 * (i - 1) + 2) = i;
    }

    // Correct the first triangle which connects the first and last vertex
    geometry.indices.at(0) = 0;
    geometry.indices.at(1) = sliceCount;
    geometry.indices.at(2) = 1;

    return ore::gl::generateGeometryBuffer(geometry);
}

