#include <GLFW/glfw3.h>
#include <iostream>
#include <glad/glad.h>
#include "Window.h"
#include "WindowSettings.h"

// A callback which allows GLFW to report errors whenever they occur
static void glfwErrorCallback(int error, const char *description)
{
    fprintf(stderr, "GLFW returned an error:\n\t%s (%i)\n", description, error);
}

GLFWwindow* ore::window::initialise(ore::WindowSettings settings)
{
    // Initialise GLFW
    if (!glfwInit())
    {
        std::cerr << "Could not start GLFW\n";
        exit(EXIT_FAILURE);
    }

    // Set core window options (adjust version numbers if needed)
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, settings.openGLMajor);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, settings.openGLMinor);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Enable the GLFW runtime error callback function defined previously.
    glfwSetErrorCallback(glfwErrorCallback);

    // Set additional window options
    glfwWindowHint(GLFW_RESIZABLE, settings.resizable);
    glfwWindowHint(GLFW_SAMPLES, settings.MSAASamplesPerPixel);

    // Create window using GLFW
    GLFWwindow* window = glfwCreateWindow(settings.width,
                                          settings.height,
                                          settings.windowTitle.c_str(),
                                          nullptr,
                                          nullptr);

    // Ensure the window is set up correctly
    if (!window)
    {
        fprintf(stderr, "Could not open GLFW window\n");
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    // Let the window be the current OpenGL context and initialise glad
    glfwMakeContextCurrent(window);
    gladLoadGL();

    // Print various OpenGL information to stdout
    std::cout << glGetString(GL_VENDOR) << ": " << glGetString(GL_RENDERER) <<std::endl;
    std::cout << "GLFW: " << glfwGetVersionString() << std::endl;
    std::cout << "OpenGL: " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLSL: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glEnable(GL_CULL_FACE);
    glClearColor(0.3f, 0.5f, 0.8f, 1.0f);

    return window;
}

void ore::window::newFrame(GLFWwindow* window) {
    // Clear colour and depth buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    int windowWidth;
    int windowHeight;
    glfwGetWindowSize(window, &windowWidth, &windowHeight);
    glViewport(0, 0, windowWidth, windowHeight);
}