#pragma once

#include "WindowSettings.h"

namespace ore {
    namespace window {
        GLFWwindow* initialise(ore::WindowSettings settings);
        void newFrame(GLFWwindow* window);
    }
}
