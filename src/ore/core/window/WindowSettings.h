#pragma once

#include <string>
#include <glm/glm.hpp>

namespace ore {
    struct WindowSettings {
        unsigned int openGLMajor = 4;
        unsigned int openGLMinor = 5;

        unsigned int width = 1920;
        unsigned int height = 1080;
        bool resizable = true;
        bool fullscreen = false;
        unsigned int monitorIndex = 0;
        unsigned int MSAASamplesPerPixel = 1;
        unsigned int frameRateLimit = 0xFFFFFFFF; // infinite
        std::string windowTitle = "ORE V3";
        glm::vec3 clearColour = {0.3f, 0.5f, 0.8f};
    };
}
