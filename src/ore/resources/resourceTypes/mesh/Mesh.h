#pragma once

#include <vector>
#include <ore/resources/resourceTypes/mesh/MeshPart.h>
#include <ore/resources/resourceTypes/mesh/MeshGeometry.h>

namespace ore {
    namespace resources {
        struct Mesh {
            ore::resources::MeshGeometry* geometry;
            std::vector<ore::resources::MeshPart> parts;
        };
    }
}