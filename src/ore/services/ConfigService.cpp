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

}
