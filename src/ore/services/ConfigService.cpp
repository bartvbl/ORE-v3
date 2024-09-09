#include <g3log/g3log.hpp>
#include <json.hpp>
#include "ConfigService.h"
#include <fstream>

void ore::ConfigService::init() {

}

void ore::ConfigService::load(ore::filesystem::path &configFile) {
    if(!ore::filesystem::exists(configFile)) {
        LOG(WARNING) << "Engine configuration file was not found: " << configFile.string() << std::endl;
        return;
    }

    nlohmann::json configFileContents;
    std::ifstream fileStream(configFile.string());
    try {
        fileStream >> configFileContents;
    } catch(nlohmann::detail::exception &e) {
        LOG(FATAL) << "Failed to load config file located at " << configFile << std::endl << "Reason:" << std::endl << e.what() << std::endl;
        throw std::runtime_error("Resource failed to load.");
    }
    fileStream.close();

    assert(configFileContents["meta"]["version"] == 1);

    ore::filesystem::path containingDirectory = configFile.parent_path();

    configuration.keyBindingConfigurationFiles.clear();
    for(const auto& entry : configFileContents["inputConfigurationFiles"]) {
        configuration.keyBindingConfigurationFiles.emplace_back(containingDirectory / std::string(entry));
    }

    if(configFileContents.contains("display")) {
        if(configFileContents["display"].contains("width")) {
            configuration.windowSettings.width = configFileContents["display"]["width"];
        }
        if(configFileContents["display"].contains("height")) {
            configuration.windowSettings.height = configFileContents["display"]["height"];
        }
        if(configFileContents["display"].contains("resizable")) {
            configuration.windowSettings.resizable = configFileContents["display"]["resizable"];
        }
        if(configFileContents["display"].contains("fullscreen")) {
            configuration.windowSettings.fullscreen = configFileContents["display"]["fullscreen"];
        }
        if(configFileContents["display"].contains("monitorIndex")) {
            configuration.windowSettings.monitorIndex = configFileContents["display"]["monitorIndex"];
        }
        if(configFileContents["display"].contains("MSAASamplesPerPixel")) {
            configuration.windowSettings.MSAASamplesPerPixel = configFileContents["display"]["MSAASamplesPerPixel"];
        }
        if(configFileContents["display"].contains("windowTitle")) {
            configuration.windowSettings.windowTitle = configFileContents["display"]["windowTitle"];
        }
        if(configFileContents["display"].contains("clearColour")) {
            configuration.windowSettings.clearColour = { configFileContents["display"]["clearColour"][0],
                                                         configFileContents["display"]["clearColour"][1],
                                                         configFileContents["display"]["clearColour"][2]};
        }
        if(configFileContents["display"].contains("frameRateLimit")) {
            configuration.windowSettings.frameRateLimit = configFileContents["display"]["frameRateLimit"];
        }
    }
}
