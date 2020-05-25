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
        public:
            virtual void draw(float progress) = 0;
            virtual void init(ore::resources::ResourceCache* cache) = 0;
        };
    }
}

