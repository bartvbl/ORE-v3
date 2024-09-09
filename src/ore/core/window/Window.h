#pragma once

#include <ore/services/ConfigService.h>
#include "WindowSettings.h"

namespace ore {
    namespace window {
        GLFWwindow* initialise(ore::WindowSettings settings);
        void newFrame(GLFWwindow* window);
        void sleepToFrameRate(const ore::ConfigService& config);
    }
}
