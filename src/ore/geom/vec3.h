#pragma once
#include <ore/geom/vec2.h>
#include <glm/glm.hpp>

namespace ore {
    namespace geom {
        struct vec3 {
            vec3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
            vec3(float* array) : x(array[0]), y(array[1]), z(array[2]) {}
            vec3(ore::geom::vec2 &other) : x(other.x), y(other.y), z(0) {}
            vec3() = default;

            // Allow automatic type conversions to glm::vec3
            glm::vec3 asglm() const {
                glm::vec3 out(x, y, z);
                return out;
            }

            float x = 0;
            float y = 0;
            float z = 0;
        };
    }
}
