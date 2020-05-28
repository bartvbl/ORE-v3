#pragma once

#include <vector>

namespace ore {
    namespace resources {
        struct MeshGeometry {
            bool hasNormals;
            bool hasTextures;
            bool hasNormalMap;

            unsigned int vertexCount;
            unsigned int indexCount;

            float* vertices;
            float* textureCoordinates;
            float* normals;

            unsigned int* indices;
        };
    }
}