#pragma once

#include <ore/resources/resourceTypes/ResourceType.h>
#include <ore/resources/resourceTypes/texture/Texture.h>

namespace ore {
    namespace resources {
        class TextureResource : public ore::resources::ResourceType {
        private:
            int imageWidth = 0;
            int imageHeight = 0;
            int channelCount = 0;
            unsigned char* imageData = nullptr;

            ore::resources::Texture texture;

        public:
            void load(const ore::filesystem::path &fileLocation) override;

            bool requiresMainThread() override;

            void completeLoadOnMainThread() override;

            void destroy() override;
        };
    }
}

