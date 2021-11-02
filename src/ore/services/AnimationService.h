#pragma once

#include <ore/animation/Transition.h>
#include <ore/sceneGraph/nodes/CoordinateNode.h>
#include <ore/geom/RelativeTransformation.h>
#include <ore/animation/BasicAnimation.h>

namespace ore {
    class AnimationService {
    private:
        std::chrono::steady_clock::time_point previousTimePoint = std::chrono::steady_clock::now();
        double getTimeDeltaSeconds();

        std::vector<ore::animation::BasicAnimation> playingAnimations;
    public:
        void init();
        void update();

        void animate(ore::scene::CoordinateNode* node, Transition transition, ore::RelativeTransformation destination);
    };
}

