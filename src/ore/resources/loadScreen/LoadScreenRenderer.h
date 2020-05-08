#pragma once

namespace ore {
    namespace resources {
        class ResourceCache;
    }
}

#include <ore/resources/ResourceCache.h>

namespace ore {
    namespace resources {
        class LoadScreenRenderer {
            virtual void init(ore::resources::ResourceCache* cache) = 0;
            virtual void draw(float progress) = 0;
        };
    }
}

