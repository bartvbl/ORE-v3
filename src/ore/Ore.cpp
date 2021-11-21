#include <GLFW/glfw3.h>
#include <ore/core/window/WindowSettings.h>
#include <ore/core/window/Window.h>
#include <glad/glad.h>
#include <ore/gl/render/RenderPass.h>
#include <ore/utilities/Logger.h>
#include <ore/geom/int2.h>
#include <ore/utilities/SceneGraphPrinter.h>
#include "Ore.h"

void ore::Engine::run(ore::filesystem::path engineConfigFileLocation, ore::GameState *initialState) {
    // Initialise logging system
    ore::Logger::init();

    // Load configuration file
    this->world.services.configService.load(engineConfigFileLocation);

    // Create OpenGL context and window
    GLFWwindow* window = ore::window::initialise(this->world.services.configService.configuration.windowSettings);

    // After context creation we can initialise services
    this->world.init(window);

    // Configure services
    this->world.services.inputService.addKeyBindingsFromFiles(this->world.services.configService.configuration.keyBindingConfigurationFiles);

    this->currentGameState = initialState;
    this->currentGameState->set(&this->world);

    // Rendering Loop
    while (!glfwWindowShouldClose(window) && !this->world.services.configService.gameShouldShutdown)
    {
        glClearColor(0.3f, 0.5f, 0.8f, 1.0f);
        ore::window::newFrame(window);
        this->currentGameState->update();
        this->world.frameTick();
        //ore::utilities::printSceneGraph(&this->world.scene.rootNode);
        ore::RenderPass::render(&this->world.scene.rootNode, window);
        glfwSwapBuffers(window);
    }

    this->currentGameState->unset();
    this->world.shutdown();
    glfwTerminate();
}
