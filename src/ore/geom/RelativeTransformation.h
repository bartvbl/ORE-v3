#pragma once
#include "vec3.h"

namespace ore {
    struct RelativeTransformation {
        ore::geom::vec3 position = {0, 0, 0};
        ore::geom::vec3 rotation = {0, 0, 0};
        float scale = 1;
    };
}

