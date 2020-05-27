#include <omp.h>
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <fstream>
#include <json.hpp>
#include "ResourceCache.h"
#include <iostream>

void ore::resources::ResourceCache::init(GLFWwindow* gameWindow) {
    this->window = gameWindow;
}

void ore::resources::ResourceCache::wakeResourceLoadingThread() {
    std::function<void()> threadJob = [this] {
        bool loadedItem = true;
        while(loadedItem) {
            loadedItem = false;
            loadedItem = loadedItem || this->textures.loadNext(ore::resources::ResourceLoadPriority::STREAMING);
            loadedItem = loadedItem || this->animations.loadNext(ore::resources::ResourceLoadPriority::STREAMING);
            loadedItem = loadedItem || this->sounds.loadNext(ore::resources::ResourceLoadPriority::STREAMING);
            loadedItem = loadedItem || this->meshes.loadNext(ore::resources::ResourceLoadPriority::STREAMING);
            loadedItem = loadedItem || this->lxfmlMeshes.loadNext(ore::resources::ResourceLoadPriority::STREAMING);
            loadedItem = loadedItem || this->shaders.loadNext(ore::resources::ResourceLoadPriority::STREAMING);
        }
    };
    this->loadingThreadPool.enqueue(threadJob);
}

void ore::resources::ResourceCache::registerSingleEntry(std::string id, ore::filesystem::path fileLocation, ore::resources::ResourceLoadPriority priority) {
    std::string extension = fileLocation.extension();
    std::transform(extension.begin(), extension.end(), extension.begin(),
                   [](unsigned char c){ return std::tolower(c); });
    if(extension == ".png") {
        this->textures.registerResource(id, priority, fileLocation);
    } else if(extension == ".mdl") {
        this->meshes.registerResource(id, priority, fileLocation);
    }
    wakeResourceLoadingThread();
}

void ore::resources::ResourceCache::enqueueResourceFile(ore::filesystem::path resourceFileLocation) {
    std::cout << "Reading resource file " << resourceFileLocation << std::endl;
    nlohmann::json resourceFile;
    std::fstream fileStream(resourceFileLocation, std::ios::in);
    fileStream >> resourceFile;
    fileStream.close();

    assert(resourceFile["meta"]["version"] == 1);

    for(const auto& entry : resourceFile["required"]) {
        registerSingleEntry(entry["id"], entry["src"], ore::resources::ResourceLoadPriority::REQUIRED);
    }
    for(const auto& entry : resourceFile["streaming"]) {
        registerSingleEntry(entry["id"], entry["src"], ore::resources::ResourceLoadPriority::STREAMING);
    }
    for(const auto& entry : resourceFile["onDemand"]) {
        registerSingleEntry(entry["id"], entry["src"], ore::resources::ResourceLoadPriority::ON_DEMAND);
    }
}

unsigned int ore::resources::ResourceCache::countEnqueuedItems(ore::resources::ResourceLoadPriority threshold) {
    unsigned int totalResourceCount = 0;
    totalResourceCount += textures.getEnqueuedItemCount(threshold);
    totalResourceCount += animations.getEnqueuedItemCount(threshold);
    totalResourceCount += sounds.getEnqueuedItemCount(threshold);
    totalResourceCount += meshes.getEnqueuedItemCount(threshold);
    totalResourceCount += lxfmlMeshes.getEnqueuedItemCount(threshold);
    totalResourceCount += shaders.getEnqueuedItemCount(threshold);
    return totalResourceCount;
}

void ore::resources::ResourceCache::runMainThreadCompletions() {
    textures.runMainThreadJobs();
    animations.runMainThreadJobs();
    sounds.runMainThreadJobs();
    meshes.runMainThreadJobs();
    lxfmlMeshes.runMainThreadJobs();
    shaders.runMainThreadJobs();
}

void ore::resources::ResourceCache::runLoadScreenSequence(ore::resources::LoadScreenRenderer *renderer,
                                                          ore::resources::ResourceLoadPriority threshold) {

    renderer->init(this);
    unsigned int totalItemsToLoad = countEnqueuedItems(threshold);
    unsigned int remainingItemsToLoad = totalItemsToLoad;

    // Do load screen render
    glClearColor(0, 0, 0, 1);

    // Rendering Loop
    while (!glfwWindowShouldClose(window) && remainingItemsToLoad > 0) {
        // Clear colour and depth buffers
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        runMainThreadCompletions();

        remainingItemsToLoad = countEnqueuedItems(threshold);
        float progress = float(totalItemsToLoad - remainingItemsToLoad) / float(totalItemsToLoad);
        renderer->draw(progress);

        glfwPollEvents();

        glfwSwapBuffers(window);
    }
}

void ore::resources::ResourceCache::shutdown() {
    this->loadingThreadPool.shutdown();
}
