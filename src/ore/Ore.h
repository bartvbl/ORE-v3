#pragma once

#include <experimental/filesystem>
#include <ore/core/GameState.h>

namespace ore {
    struct Engine {
        void run(
            std::experimental::filesystem::path engineConfigFileLocation,
            ore::GameState* initialState
        );
    };
}

