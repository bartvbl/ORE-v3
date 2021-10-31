#pragma once

#include <ore/gameObjects/GameObject.h>
#include <ore/sceneGraph/nodes/PerspectiveCamera.h>
#include <ore/services/InputService.h>
#include <ore/world/GameWorld.h>

namespace ore {
    class BuiltinEngineKeybinds : public ore::GameObject {
    private:
        ore::WorldServices* services;
        bool quitRequested = false;
    public:
        BuiltinEngineKeybinds(ore::WorldServices* services) : services(services) {
            services->inputService.attachListener("instantQuit", &quitRequested);
        }

        void update();
    };
}
