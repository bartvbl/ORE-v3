#pragma once

#include <ore/utilities/filesystem.h>
#include <ore/resouces/loadScreen/LoadScreenRenderer.h>

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
            void init();

            void enqueueResourceFile(
                    ore::filesystem::path resourceFileLocation);

            void runLoadScreenSequence(
                    ore::resources::LoadScreenRenderer* renderer,
                    ore::resources::ResourceLoadPriority threshold);
        };
    }
}

