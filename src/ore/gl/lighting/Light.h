#pragma once

#include <ore/gl/lighting/LightType.h>

#include "json.hpp"

namespace ore {
    namespace gl {
        struct Light {
            ore::gl::LightType type = LightType::POINT_LIGHT;

            glm::vec3 position = {0, 0, 0};
            glm::vec3 lightDirection = {0, 0, 0};
            glm::vec3 lightColour = {1, 1, 1};
            float spotLightAngleDegrees = 90;
            float attenuation = 5;
            float directionalLightRadius = 5;
            bool enableLightOutsideShadowMap = false;
            bool showLightBeams = false;
        };
    }
}
