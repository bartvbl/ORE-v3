#pragma once

#include <vector>
#include <ore/resources/resourceTypes/mesh/MeshPart.h>
#include <ore/resources/resourceTypes/mesh/MeshGeometry.h>
#include "MeshMaterials.h"

namespace ore {
    namespace resources {
        struct Mesh {
            ore::resources::MeshGeometry geometry;
            ore::resources::MeshMaterials materials;
            ore::resources::MeshPart rootPart;
        };
    }
}