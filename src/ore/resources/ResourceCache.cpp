#include <omp.h>
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include "ResourceCache.h"

void ore::resources::ResourceCache::init(GLFWwindow* gameWindow) {
    this->window = gameWindow;
}

void ore::resources::ResourceCache::enqueueResourceFile(ore::filesystem::path resourceFileLocation) {

}

void ore::resources::ResourceCache::runLoadScreenSequence(ore::resources::LoadScreenRenderer *renderer,
                                                          ore::resources::ResourceLoadPriority threshold) {



    // Do load screen render
    #pragma omp parallel
    {

        if(omp_get_thread_num() == 0) {
            glClearColor(0, 0, 0, 1);

            // Rendering Loop
            while (!glfwWindowShouldClose(window))
            {
                // Clear colour and depth buffers
                glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

                glfwPollEvents();

                glfwSwapBuffers(window);
            }
        }
    };
}
