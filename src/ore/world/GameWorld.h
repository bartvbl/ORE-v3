#pragma once

#include <ore/resources/ResourceCache.h>
#include <ore/services/AIService.h>
#include <ore/services/AnimationService.h>
#include <ore/services/InputService.h>
#include <ore/services/SoundService.h>
#include <ore/services/ConfigService.h>
#include <ore/sceneGraph/Scene.h>
#include <ore/world/Actors.h>
#include <GLFW/glfw3.h>
#include "ore/services/PhysicsService.h"

namespace ore {
    struct WorldServices {
        ore::AIService aiService;
        ore::AnimationService animationService;
        ore::InputService inputService;
        ore::SoundService soundService;
        ore::ConfigService configService;
        ore::PhysicsService physicsService;
    };

    class GameWorld {
    public:
        ore::resources::ResourceCache resourceCache;
        ore::WorldServices services;
        ore::Scene scene;
        ore::Actors actors;
        GLFWwindow* window = nullptr;

        GameWorld() : resourceCache(5) {}

        void init(GLFWwindow* window);

        void frameTick();

        void shutdown();
    };
}

