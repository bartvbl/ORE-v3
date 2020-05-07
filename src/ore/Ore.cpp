#include <GLFW/glfw3.h>
#include <ore/core/window/WindowSettings.h>
#include <ore/core/window/Window.h>
#include <glad/glad.h>
#include <ore/gl/RenderPass.h>
#include "Ore.h"

void handleKeyboardInput(GLFWwindow* window)
{
    // Use escape key for terminating the GLFW window
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
}

void ore::Engine::run(ore::filesystem::path engineConfigFileLocation, ore::GameState *initialState) {
    // Create OpenGL context and window
    ore::WindowSettings settings;
    GLFWwindow* window = ore::window::initialise(settings);

    // After context creation we can initialise services
    this->world.init();

    this->currentGameState = initialState;

    // Rendering Loop
    while (!glfwWindowShouldClose(window))
    {
        // Clear colour and depth buffers
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glfwPollEvents();
        handleKeyboardInput(window);

        this->world.frameTick();

        ore::RenderPass::render(&this->world.scene.rootNode);

        glfwSwapBuffers(window);
    }

    glfwTerminate();
}
