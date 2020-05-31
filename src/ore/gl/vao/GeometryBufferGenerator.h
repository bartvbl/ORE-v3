#pragma once

#include "GeometryBuffer.h"
#include <ore/resources/resourceTypes/mesh/Mesh.h>

namespace ore {
    namespace gl {
        ore::gl::GeometryBuffer generateGeometryBuffer(const ore::resources::MeshGeometry &geometry);
    }
}
