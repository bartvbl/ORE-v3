#pragma once

#include <ore/resources/resourceTypes/ResourceType.h>

namespace ore {
    namespace resources {
        class VideoResource final : public ore::resources::ResourceType {
        private:
            std::filesystem::path targetFile;
        public:
            void load(const ore::filesystem::path &fileLocation) override;
            std::filesystem::path getVideoFileLocation();

            bool requiresMainThread() override;

            void completeLoadOnMainThread() override;

            void destroy() override;


        };
    }
}

