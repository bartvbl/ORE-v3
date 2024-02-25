#pragma once

#include <ore/utilities/filesystem.h>
#include <ore/resources/resourceTypes/ResourceType.h>
#include <ore/resources/loadScreen/LoadScreenRenderer.h>
#include <ore/resources/resourceTypes/TextureResource.h>
#include <ore/resources/resourceTypes/MeshResource.h>
#include <ore/resources/resourceTypes/AnimationResource.h>
#include <ore/resources/resourceTypes/LXFMLResource.h>
#include <ore/resources/resourceTypes/ShaderResource.h>
#include <ore/resources/resourceTypes/FontResource.h>
#include <ore/resources/resourceTypes/SoundResource.h>
#include <ore/resources/resourceTypes/VideoResource.h>
#include <ore/resources/ResourceContainer.h>
#include <ore/resources/ResourceLoadPriority.h>
#include <GLFW/glfw3.h>
#include <ore/utilities/Threadpool.h>

namespace ore {
    namespace resources {
        // Forward declaration due to both relying on one another
        class LoadScreenRenderer;

        class ResourceCache {
        private:
            GLFWwindow* window;
            ore::utilities::Threadpool loadingThreadPool;
            unsigned int countEnqueuedItems(ore::resources::ResourceLoadPriority threshold);

            void registerSingleEntry(std::string id, ore::filesystem::path fileLocation, ore::resources::ResourceLoadPriority priority);
            void wakeResourceLoadingThread();
        public:
            ore::resources::ResourceContainer<ore::resources::TextureResource> textures;
            ore::resources::ResourceContainer<ore::resources::MeshResource> meshes;
            ore::resources::ResourceContainer<ore::resources::AnimationResource> animations;
            ore::resources::ResourceContainer<ore::resources::SoundResource> sounds;
            ore::resources::ResourceContainer<ore::resources::LXFMLResource> lxfmlMeshes;
            ore::resources::ResourceContainer<ore::resources::ShaderResource> shaders;
            ore::resources::ResourceContainer<ore::resources::FontResource> fonts;
            ore::resources::ResourceContainer<ore::resources::VideoResource> videos;
            ore::resources::ResourceContainer<ore::resources::ResourceType> customResources;

            ResourceCache(unsigned int resourceLoadingThreadCount) : loadingThreadPool(resourceLoadingThreadCount) {}

            void init(GLFWwindow* window);

            void enqueueResourceFile(
                    ore::filesystem::path resourceFileLocation);

            void runLoadScreenSequence(
                    ore::resources::LoadScreenRenderer* renderer,
                    ore::resources::ResourceLoadPriority threshold);

            void flushMainThreadCompletions();

            void shutdown();


        };
    }
}

