#pragma once

#include <ore/utilities/filesystem.h>
#include <ore/resources/loadScreen/LoadScreenRenderer.h>
#include <ore/resources/resourceTypes/TextureResource.h>
#include <ore/resources/resourceTypes/MeshResource.h>
#include <ore/resources/resourceTypes/AnimationResource.h>
#include <ore/resources/resourceTypes/LXFMLResource.h>
#include <ore/resources/resourceTypes/ShaderResource.h>
#include <ore/resources/resourceTypes/SoundResource.h>
#include <ore/resources/ResourceContainer.h>

namespace ore {
    namespace resources {
        // Forward declaration due to both relying on one another
        class LoadScreenRenderer;

        enum class ResourceLoadPriority {
            // Must be present in the cache at all times
            REQUIRED,
            // Must eventually be in the cache, but not within the next few minutes after the loading screen completes
            STREAMING,
            // Keep unloaded unless requested
            ON_DEMAND
        };

        class ResourceCache {
        public:
            ore::resources::ResourceContainer<ore::resources::TextureResource> textures;
            ore::resources::ResourceContainer<ore::resources::MeshResource> meshes;
            ore::resources::ResourceContainer<ore::resources::AnimationResource> animations;
            ore::resources::ResourceContainer<ore::resources::SoundResource> sounds;
            ore::resources::ResourceContainer<ore::resources::LXFMLResource> lxfmlMeshes;
            ore::resources::ResourceContainer<ore::resources::ShaderResource> shaders;

            void init();

            void enqueueResourceFile(
                    ore::filesystem::path resourceFileLocation);

            void runLoadScreenSequence(
                    ore::resources::LoadScreenRenderer* renderer,
                    ore::resources::ResourceLoadPriority threshold);
        };
    }
}

