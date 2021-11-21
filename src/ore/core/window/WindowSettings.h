#pragma once

#include <string>

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
    };
}
