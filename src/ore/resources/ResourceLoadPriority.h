#pragma once

namespace ore {
    namespace resources {
        enum class ResourceLoadPriority {
            // Must be present in the cache at all times
            REQUIRED,
            // Must eventually be in the cache, but not within the next few minutes after the loading screen completes
            STREAMING,
            // Keep unloaded unless requested
            ON_DEMAND
        };
    }
}
