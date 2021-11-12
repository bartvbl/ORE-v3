#pragma once

#include <ore/animation/TransitionType.h>
#include <ore/geom/RelativeTransformation.h>
#include <ore/sceneGraph/nodes/CoordinateNode.h>
#include "Transition.h"

namespace ore {
    namespace animation {
        struct BasicAnimation {
            ore::RelativeTransformation start;
            ore::RelativeTransformation end;

            ore::Transition transition;
            double progressionSeconds = 0.0;

            ore::scene::CoordinateNode* target = nullptr;

            BasicAnimation(ore::scene::CoordinateNode* target, ore::RelativeTransformation destination, ore::Transition transition)
                : end(destination), transition(transition), target(target) {
                start.position = target->position;
                start.rotation = target->rotation;
                start.scale = target->scale;
            }

            bool animate(double timeDelta);
        };
    }
}