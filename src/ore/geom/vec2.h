#pragma once

namespace ore {
    namespace geom {
        struct vec2 {
            vec2(float _x, float _y) : x(_x), y(_y) {}
            vec2() = default;

            float x = 0;
            float y = 0;
        };
    }
}