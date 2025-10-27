#pragma once

#include <ore/utilities/filesystem.h>
#include <ore/core/GameState.h>
#include <ore/world/GameWorld.h>

namespace ore {
    class Engine {
    private:
        ore::GameWorld world;
        std::shared_ptr<ore::GameState> currentGameState;

    public:
        void run(
            ore::filesystem::path engineConfigFileLocation,
            std::shared_ptr<ore::GameState> initialState
        );
    };
}

