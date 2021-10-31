#pragma once
#include <ore/geom/vec2.h>
#include <glm/glm.hpp>

namespace ore {
    namespace geom {
        struct vec3 {
            float x = 0;
            float y = 0;
            float z = 0;

            vec3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
            vec3(float* array) : x(array[0]), y(array[1]), z(array[2]) {}
            vec3(ore::geom::vec2 &other) : x(other.x), y(other.y), z(0) {}
            vec3() = default;

            // Allow automatic type conversions to glm::vec3
            [[nodiscard]] glm::vec3 asglm() const {
                glm::vec3 out(x, y, z);
                return out;
            }

            vec3 operator* (float multiplier) const {
                return {x * multiplier, y * multiplier, z * multiplier};
            }

            vec3 operator* (int multiplier) const {
                return {x * float(multiplier), y * float(multiplier), z * float(multiplier)};
            }

            vec3 operator- () const {
                return {-x, -y, -z};
            }
        };
    }
}
