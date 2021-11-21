#pragma once

#include <string>
#include <glm/glm.hpp>

namespace ore {
    struct WindowSettings {
        unsigned int openGLMajor = 4;
        unsigned int openGLMinor = 5;

        unsigned int width = 1024;
        unsigned int height = 768;
        bool resizable = true;
        bool fullscreen = false;
        unsigned int monitorIndex = 0;
        unsigned int MSAASamplesPerPixel = 1;
        std::string windowTitle = "ORE V3";
        glm::vec3 clearColour = {0.3f, 0.5f, 0.8f};
    };
}
