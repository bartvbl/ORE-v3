#pragma once

#include <ore/animation/TransitionType.h>

namespace ore {
    namespace animation {
        struct BasicAnimation {
            ore::geom::vec3 startPosition = {0, 0, 0};
            ore::geom::vec3 startRotation = {0, 0, 0};
            ore::geom::vec3 startScale = {0, 0, 0};

            ore::geom::vec3 endPosition = {0, 0, 0};
            ore::geom::vec3 endRotation = {0, 0, 0};
            ore::geom::vec3 endScale = {0, 0, 0};

            double durationSeconds = 1.0;
            double progressionSeconds = 0.0;
            ore::TransitionType type = ore::TransitionType::LINEAR;

            ore::scene::CoordinateNode* target = nullptr;
        };
    }
}