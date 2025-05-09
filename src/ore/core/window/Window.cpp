#include <GLFW/glfw3.h>
#include <iostream>
#include <glad/glad.h>
#include "Window.h"
#include "WindowSettings.h"
#include <array>
#include <g3log/g3log.hpp>

// A callback which allows GLFW to report errors whenever they occur
static void glfwErrorCallback(int error, const char *description)
{
    fprintf(stderr, "GLFW returned an error:\n\t%s (%i)\n", description, error);
}

void APIENTRY openglDebugCallback(GLenum source,
                                   GLenum type,
                                   GLuint id,
                                   GLenum severity,
                                   GLsizei length,
                                   const GLchar *message,
                                   const void *userParam) {
#ifdef NDEBUG
    // nondebug
#else
    std::cout << "--- OpenGL Error ---" << std::endl;
    std::string errorString;

    switch(type) {
        case GL_INVALID_ENUM:
            errorString = "GL_INVALID_ENUM";
            break;
        case GL_INVALID_OPERATION:
            errorString = "GL_INVALID_OPERATION";
            break;
        case GL_INVALID_FRAMEBUFFER_OPERATION_EXT:
            errorString = "GL_INVALID_FRAMEBUFFER_OPERATION";
            break;
        case GL_OUT_OF_MEMORY:
            errorString = "GL_OUT_OF_MEMORY";
            break;
        case GL_STACK_UNDERFLOW:
            errorString = "GL_STACK_UNDERFLOW";
            break;
        case GL_STACK_OVERFLOW:
            errorString = "GL_STACK_OVERFLOW";
            break;
        default:
            errorString = "[Unknown error ID]";
            break;
    }
    std::cout << type << " - " << message << std::endl;
    if(severity == GL_DEBUG_SEVERITY_HIGH || severity == GL_DEBUG_SEVERITY_MEDIUM)
    throw std::runtime_error(message);
#endif

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
    GLFWmonitor* monitor = nullptr;
    GLFWmonitor** monitors;
    if(settings.fullscreen) {
        int monitorCount = 0;
        monitors = glfwGetMonitors(&monitorCount);
        if((int)settings.monitorIndex >= monitorCount) {
            monitor = glfwGetPrimaryMonitor();
            LOG(WARNING) << "The requested monitor index " << settings.monitorIndex << " is out of range because this system only has " << monitorCount << " monitors available. Falling back to the default monitor instead." << std::endl;
        } else {
            monitor = monitors[settings.monitorIndex];
        }
    }

    GLFWwindow* window = glfwCreateWindow(settings.width,
                                          settings.height,
                                          settings.windowTitle.c_str(),
                                          monitor,
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
    std::cout << "Display" << settings.width << "x" << settings.height << std::endl;
    std::cout << "GLFW: " << glfwGetVersionString() << std::endl;
    std::cout << "OpenGL: " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLSL: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glEnable(GL_CULL_FACE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glClearColor(settings.clearColour.x, settings.clearColour.y, settings.clearColour.z, 1.0f);

    glEnable(GL_DEBUG_OUTPUT);
    glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
    glDebugMessageCallback(&openglDebugCallback, nullptr);

    return window;
}

void ore::window::newFrame(GLFWwindow *window, const WindowSettings& settings) {
    // Clear colour and depth buffers
    glClearColor(settings.clearColour.x, settings.clearColour.y, settings.clearColour.z, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    int windowWidth;
    int windowHeight;
    glfwGetWindowSize(window, &windowWidth, &windowHeight);
    glViewport(0, 0, windowWidth, windowHeight);
}

void ore::window::sleepToFrameRate(const ore::ConfigService &config) {
    static bool hasBeenInitialised = false;
    static std::chrono::time_point<std::chrono::steady_clock> previousCallTime;

    if(!hasBeenInitialised) {
        hasBeenInitialised = true;
        previousCallTime = std::chrono::steady_clock::now();
        return;
    }

    std::chrono::time_point<std::chrono::steady_clock> currentCallTime = std::chrono::steady_clock::now();
    std::chrono::duration timeDifference = currentCallTime - previousCallTime;
    previousCallTime = currentCallTime;

    double elapsedTimeSincePreviousCall = double(std::chrono::duration_cast<std::chrono::nanoseconds>(timeDifference).count()) / 1000000000.0;
    double targetFrameRate = config.configuration.windowSettings.frameRateLimit;
    double minFrameTime = 1.0 / targetFrameRate;
    if(elapsedTimeSincePreviousCall < minFrameTime) {
        // Wait some time if the frame was computed too quickly
        double timeToWaitSeconds = minFrameTime - elapsedTimeSincePreviousCall;
        std::this_thread::sleep_for(std::chrono::nanoseconds(uint64_t(1000000000.0 * timeToWaitSeconds)));
    }
}
