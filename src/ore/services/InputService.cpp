#include <GLFW/glfw3.h>
#include "InputService.h"

void ore::InputService::init(GLFWwindow* window) {
    this->gameWindow = window;
}

void ore::InputService::tick() {
    glfwPollEvents();

    // Use escape key for terminating the GLFW window
    if (glfwGetKey(gameWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(gameWindow, true);
    }

}

