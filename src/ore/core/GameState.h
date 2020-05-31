#pragma once

#include <ore/resources/loadScreen/LoadScreenRenderer.h>
#include <ore/world/GameWorld.h>

namespace ore {
    class GameState {

    public:
        virtual void update() = 0;
        virtual void set(ore::GameWorld* world) = 0;
        virtual void unset() = 0;
    };
}