#include <ore/resources/resourceTypes/mesh/MeshGeometry.h>
#include <ore/gl/vao/GeometryBufferGenerator.h>
#include "PrimitiveGenerator.h"

ore::scene::GeometryNode ore::gl::PrimitiveGenerator::generatePlaneBuffer() {
    ore::resources::MeshGeometry geometry;
    geometry.vertices = {
            glm::vec3(0, 0, 0),
            glm::vec3(1, 0, 0),
            glm::vec3(1, 1, 0),
            glm::vec3(0, 1, 0)};
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