#pragma once

#include <vector>
#include <ore/geom/vec2.h>

namespace ore {
    namespace resources {
        struct MeshGeometry {
            bool hasNormals = false;
            bool hasTextures = false;
            bool hasNormalMap = false;

            std::vector<ore::geom::vec3> vertices;
            std::vector<ore::geom::vec2> textureCoordinates;
            std::vector<ore::geom::vec3> normals;

            std::vector<unsigned int> indices;
        };
    }
}