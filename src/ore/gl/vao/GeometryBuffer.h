#pragma once

namespace ore {
    namespace gl {
        struct GeometryBuffer {
            int vaoID = -1;

            unsigned int indexCount = 0;

            int vertexBufferID = -1;
            int normalBufferID = -1;
            int textureBufferID = -1;
            int indexBufferID = -1;
        };
    }
}