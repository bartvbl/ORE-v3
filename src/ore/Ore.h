#pragma once

#include <ore/utilities/filesystem.h>
#include <ore/core/GameState.h>
#include <ore/world/GameWorld.h>

namespace ore {
    class Engine {
    private:
        ore::GameWorld world;
        ore::GameState* currentGameState;

    public:
        void run(
            ore::filesystem::path engineConfigFileLocation,
            ore::GameState* initialState
        );
    };
}

