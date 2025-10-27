#pragma once

#include <ore/services/ConfigService.h>
#include "WindowSettings.h"

namespace ore {
    namespace window {
        GLFWwindow* initialise(ore::WindowSettings settings);
        void newFrame(GLFWwindow *window, const WindowSettings& settings);
        void sleepToFrameRate(const ore::ConfigService& config);
        void update(GLFWwindow *window, const WindowSettings& window_settings);
    }
}
