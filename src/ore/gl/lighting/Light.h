#pragma once

#include <ore/gl/lighting/LightType.h>

namespace ore {
    namespace gl {
        struct Light {
            ore::gl::LightType type = LightType::POINT_LIGHT;

            glm::vec3 position = {0, 0, 0};
            glm::vec3 lightDirection = {0, 0, 0};
            float spotLightAngleDegrees = 30;
            float attenuation = 5;
        };
    }
}