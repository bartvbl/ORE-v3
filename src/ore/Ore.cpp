#include <GLFW/glfw3.h>
#include <ore/core/window/WindowSettings.h>
#include <ore/core/window/Window.h>
#include <glad/glad.h>
#include <ore/gl/render/RenderPass.h>
#include <ore/utilities/Logger.h>
#include "Ore.h"

void ore::Engine::run(ore::filesystem::path engineConfigFileLocation, ore::GameState *initialState) {
    // Initialise logging system
    ore::Logger::init();

    // Create OpenGL context and window
    ore::WindowSettings settings;
    GLFWwindow* window = ore::window::initialise(settings);

    // After context creation we can initialise services
    this->world.init(window);

    this->currentGameState = initialState;
    this->currentGameState->set(&this->world);

    // Rendering Loop
    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.3f, 0.5f, 0.8f, 1.0f);
        ore::window::newFrame(window);
        this->currentGameState->update();
        this->world.frameTick();
        ore::RenderPass::render(&this->world.scene.rootNode);
        glfwSwapBuffers(window);
    }

    this->currentGameState->unset();
    this->world.shutdown();
    glfwTerminate();
}
