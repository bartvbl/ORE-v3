#pragma once
#include <ore/utilities/filesystem.h>
#include <ore/services/input/InputType.h>

namespace ore {
    class InputService {
    private:
        GLFWwindow* gameWindow;

    public:
        void init(GLFWwindow* gameWindow);
        void tick();

        void addKeyBindingsFromFile(ore::filesystem::path bindingsFile);
        void addKeyBinding(ore::input::InputType key, std::string binding);
        void saveKeyBindingsToFile(ore::filesystem::path bindingsFile);
    };
}

