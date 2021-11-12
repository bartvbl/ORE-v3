#pragma once

namespace ore {
    namespace geom {
        struct vec4 {
            vec4(float _x, float _y, float _z, float _w) : x(_x), y(_y), z(_z), w(_w) {}
            vec4(float* xyzArray, float w) : x(xyzArray[0]), y(xyzArray[1]), z(xyzArray[2]), w(w) {}
            vec4() = default;

            float x = 0;
            float y = 0;
            float z = 0;
            float w = 0;
        };
    }
}