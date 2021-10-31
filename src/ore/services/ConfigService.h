#pragma once

#include <ore/utilities/filesystem.h>

namespace ore {
    struct Configuration {
        std::vector<ore::filesystem::path> keyBindingConfigurationFiles;
    };

    class ConfigService {
    public:
        bool gameShouldShutdown = false;

        void init();
        void load(ore::filesystem::path &configFile);

        Configuration configuration;
    };
}