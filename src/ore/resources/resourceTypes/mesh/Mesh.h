#pragma once

#include <vector>
#include <ore/resources/resourceTypes/mesh/MeshPart.h>
#include <ore/resources/resourceTypes/mesh/MeshGeometry.h>
#include "MeshMaterials.h"

namespace ore {
    namespace resources {
        struct Mesh {
            ore::resources::MeshGeometry geometry;
            std::vector<Material> materials;

            // To iterate over parts, start at the root part at index 0,
            // then look at the number of child nodes to determine how many nodes to visit at this level
            // Repeat recursively.
            // This implies iterating over this list is effectively a depth-first search
            std::vector<ore::resources::MeshPart> parts;
        };
    }
}