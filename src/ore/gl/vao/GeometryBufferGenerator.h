#pragma once

#include "GeometryBuffer.h"
#include <ore/resources/resourceTypes/mesh/Mesh.h>

namespace ore {
    namespace gl {
        ore::gl::GeometryBuffer generateGeometryBuffer(const ore::resources::MeshGeometry &geometry, unsigned int drawMode = 0xFFFFFFFF);
        void updateGeometryBuffer(const ore::resources::MeshGeometry &geometry, ore::gl::GeometryBuffer& buffer,  unsigned int drawMode = 0xFFFFFFFF);
        ore::gl::GeometryBuffer createStreamingGeometryBuffer();
    }
}
