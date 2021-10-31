#pragma once

#include <ore/animation/Transition.h>
#include <ore/sceneGraph/nodes/CoordinateNode.h>

namespace ore {
    class AnimationService {

    public:
        void init();
        void update();

        void animate(ore::scene::CoordinateNode* node, Transition transition);
    };
}

