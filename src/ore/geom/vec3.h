#pragma once

namespace ore {
    namespace geom {
        struct vec3 {
            vec3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
            vec3(float* array) : x(array[0]), y(array[1]), z(array[2]) {}
            vec3() = default;

            float x = 0;
            float y = 0;
            float z = 0;
        };
    }
}
