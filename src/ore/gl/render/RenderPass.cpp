#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "RenderPass.h"

void ore::RenderPass::render(ore::SceneNode *rootNode, GLFWwindow* window) {
    int windowWidth;
    int windowHeight;
    glfwGetWindowSize(window, &windowWidth, &windowHeight);

    ore::RenderState state;
    state.window.width = windowWidth;
    state.window.height = windowHeight;

    rootNode->update(state);
    rootNode->render(state);
}