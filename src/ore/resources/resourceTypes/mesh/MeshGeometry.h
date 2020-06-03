#pragma once

#include <vector>
#include <glm/glm.hpp>

namespace ore {
    namespace resources {
        struct MeshGeometry {
            bool hasNormals = false;
            bool hasTextures = false;
            bool hasNormalMap = false;

            std::vector<glm::vec3> vertices;
            std::vector<glm::vec2> textureCoordinates;
            std::vector<glm::vec3> normals;

            std::vector<unsigned int> indices;
        };
    }
}