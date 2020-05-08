#pragma once

#include <ore/resources/resourceTypes/ResourceType.h>

namespace ore {
    namespace resources {
        class LXFMLResource : public ore::resources::ResourceType {
            void load() override;

            bool requiresMainThread() override;

            void completeLoadOnMainThread() override;
        };
    }
}

