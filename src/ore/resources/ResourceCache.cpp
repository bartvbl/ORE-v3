#include <omp.h>
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <fstream>
#include <json.hpp>
#include "ResourceCache.h"
#include <iostream>
#include <ore/core/window/Window.h>
#include <ore/gl/GLError.h>
#include <g3log/loglevels.hpp>
#include <g3log/g3log.hpp>

void ore::resources::ResourceCache::init(GLFWwindow* gameWindow) {
    this->window = gameWindow;
}

void ore::resources::ResourceCache::wakeResourceLoadingThread() {
    std::function<void()> threadJob = [this] {
        bool anItemWasLoaded = true;
        while(anItemWasLoaded) {
            anItemWasLoaded = false;
            anItemWasLoaded = anItemWasLoaded
                || this->textures.loadNext(ore::resources::ResourceLoadPriority::STREAMING);
            anItemWasLoaded = anItemWasLoaded
                || this->animations.loadNext(ore::resources::ResourceLoadPriority::STREAMING);
            anItemWasLoaded = anItemWasLoaded
                || this->sounds.loadNext(ore::resources::ResourceLoadPriority::STREAMING);
            anItemWasLoaded = anItemWasLoaded
                || this->meshes.loadNext(ore::resources::ResourceLoadPriority::STREAMING);
            anItemWasLoaded = anItemWasLoaded
                || this->lxfmlMeshes.loadNext(ore::resources::ResourceLoadPriority::STREAMING);
            anItemWasLoaded = anItemWasLoaded
                || this->shaders.loadNext(ore::resources::ResourceLoadPriority::STREAMING);
            anItemWasLoaded = anItemWasLoaded
                || this->fonts.loadNext(ore::resources::ResourceLoadPriority::STREAMING);
            anItemWasLoaded = anItemWasLoaded
                || this->videos.loadNext(ore::resources::ResourceLoadPriority::STREAMING);
            anItemWasLoaded = anItemWasLoaded
                || this->customResources.loadNext(ore::resources::ResourceLoadPriority::STREAMING);
        }
    };
    this->loadingThreadPool.enqueue(threadJob);
}

void ore::resources::ResourceCache::registerSingleEntry(std::string id, ore::filesystem::path fileLocation, ore::resources::ResourceLoadPriority priority) {
    std::string extension = fileLocation.extension().string();

    if(!ore::filesystem::exists(fileLocation) && extension != ".shader") {
        LOG(FATAL) << "The file of the resource with ID " << id << ", located at " << fileLocation.string() << " could not be found.";
    }

    std::transform(extension.begin(), extension.end(), extension.begin(),
                   [](unsigned char c){ return std::tolower(c); });
    if(extension == ".png" || extension == ".bmp" || extension == ".tga" || extension == ".jpg") {
        this->textures.registerResource(id, priority, fileLocation, new TextureResource());
    } else if(extension == ".mdl" || extension == ".obj") {
        this->meshes.registerResource(id, priority, fileLocation, new MeshResource());
    } else if(extension == ".shader") {
        this->shaders.registerResource(id, priority, fileLocation, new ShaderResource());
    } else if(extension == ".ttf") {
        this->fonts.registerResource(id, priority, fileLocation, new FontResource());
    } else if(extension == ".mp4") {
        this->videos.registerResource(id, priority, fileLocation, new VideoResource());
    } else if(extension == ".mp3" || extension == ".wav") {
        this->sounds.registerResource(id, priority, fileLocation, new SoundResource());
    } else {
        LOG(FATAL) << "The resource with ID " << id << ", located at " << fileLocation << " has an unknown extension, and can therefore not be loaded as a resource." << std::endl;
    }
    wakeResourceLoadingThread();
}

void checkResourceFileEntry(const ore::filesystem::path &resourceFileLocation, const nlohmann::json &entry) {
    if(entry.find("id") == entry.end()) {
        LOG(FATAL) << "Error: entry in resource file '" << resourceFileLocation.string() << "' is missing the property 'id'." << std::endl;
    }
    if(entry.find("src") == entry.end()) {
        LOG(FATAL) << "Error: entry in resource file '" << resourceFileLocation.string() << "' is missing the property 'src'." << std::endl;
    }
}

void ore::resources::ResourceCache::enqueueResourceFile(ore::filesystem::path resourceFileLocation) {
    std::cout << "Reading resource file " << resourceFileLocation << std::endl;
    ore::filesystem::path resListDirectory = resourceFileLocation.parent_path();
    nlohmann::json resourceFile;
    std::fstream fileStream(resourceFileLocation, std::ios::in);
    fileStream >> resourceFile;
    fileStream.close();

    assert(resourceFile["meta"]["version"] == 1);

    for(const auto& entry : resourceFile["required"]) {
        checkResourceFileEntry(resourceFileLocation, entry);
        registerSingleEntry(entry["id"],
                resListDirectory / ore::filesystem::path(std::string(entry["src"])),
                ore::resources::ResourceLoadPriority::REQUIRED);
    }
    for(const auto& entry : resourceFile["streaming"]) {
        checkResourceFileEntry(resourceFileLocation, entry);
        registerSingleEntry(entry["id"],
                resListDirectory / ore::filesystem::path(std::string(entry["src"])),
                ore::resources::ResourceLoadPriority::STREAMING);
    }
    for(const auto& entry : resourceFile["onDemand"]) {
        checkResourceFileEntry(resourceFileLocation, entry);
        registerSingleEntry(entry["id"],
                resListDirectory / ore::filesystem::path(std::string(entry["src"])),
                ore::resources::ResourceLoadPriority::ON_DEMAND);
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
    totalResourceCount += fonts.getEnqueuedItemCount(threshold);
    totalResourceCount += customResources.getEnqueuedItemCount(threshold);
    return totalResourceCount;
}

void ore::resources::ResourceCache::flushMainThreadCompletions() {
    textures.runMainThreadJobs();
    animations.runMainThreadJobs();
    sounds.runMainThreadJobs();
    meshes.runMainThreadJobs();
    lxfmlMeshes.runMainThreadJobs();
    shaders.runMainThreadJobs();
    fonts.runMainThreadJobs();
    customResources.runMainThreadJobs();
}

void ore::resources::ResourceCache::runLoadScreenSequence(ore::resources::LoadScreenRenderer *renderer, ore::resources::ResourceLoadPriority threshold) {

    renderer->init(this);
    unsigned int totalItemsToLoad = countEnqueuedItems(threshold);
    std::cout << "Initial number of items to load: " << totalItemsToLoad << std::endl;
    unsigned int remainingItemsToLoad = totalItemsToLoad;
    wakeResourceLoadingThread();

    WindowSettings settings;
    settings.clearColour = {0, 0, 0};

    // Rendering Loop
    while (!glfwWindowShouldClose(window) && remainingItemsToLoad > 0) {
        ore::window::newFrame(window, settings);

        flushMainThreadCompletions();

        remainingItemsToLoad = countEnqueuedItems(threshold);
        float progress = float(totalItemsToLoad - remainingItemsToLoad) / float(totalItemsToLoad);
        renderer->draw(progress);

        glfwPollEvents();

        glfwSwapBuffers(window);
    }

    std::cout << "Loading complete!\n";
}

void ore::resources::ResourceCache::shutdown() {
    this->loadingThreadPool.shutdown();
}
