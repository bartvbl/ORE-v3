#pragma once

#include <ore/utilities/filesystem.h>
#include <ore/core/window/WindowSettings.h>

namespace ore {
    struct Configuration {
        std::vector<ore::filesystem::path> keyBindingConfigurationFiles;
        ore::WindowSettings windowSettings;
    };

    class ConfigService {
    public:
        bool gameShouldShutdown = false;

        void init();
        void load(ore::filesystem::path &configFile);

        Configuration configuration;
    };
}