#pragma once

#include <ore/resouces/ResourceCache.h>
#include <ore/services/AIService.h>
#include <ore/services/AnimationService.h>
#include <ore/services/InputService.h>
#include <ore/services/SoundService.h>
#include <ore/sceneGraph/Scene.h>

namespace ore {
    struct WorldServices {
        ore::AIService aiService;
        ore::AnimationService animationService;
        ore::InputService inputService;
        ore::SoundService soundService;
    };

    class GameWorld {
    public:
        ore::resources::ResourceCache resourceCache;
        ore::WorldServices services;
        ore::Scene scene;

        void init();

        void frameTick();
    };
}

