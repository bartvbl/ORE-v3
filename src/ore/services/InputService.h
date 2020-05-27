#pragma once

namespace ore {
    class InputService {
    private:
        GLFWwindow* gameWindow;

    public:
        void init(GLFWwindow* gameWindow);
        void tick();
    };
}

