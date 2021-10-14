#pragma once

#include <ore/resources/resourceTypes/ResourceType.h>

namespace ore {
    namespace resources {
        class SoundResource final : public ore::resources::ResourceType {
            void load(const ore::filesystem::path &fileLocation) override;

            bool requiresMainThread() override;

            void completeLoadOnMainThread() override;

            void destroy() override;
        };
    }
}

