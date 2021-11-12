#pragma once

#include <ore/resources/resourceTypes/ResourceType.h>
#include <ore/resources/resourceTypes/texture/Texture.h>

namespace ore {
    namespace resources {
        class TextureResource final : public ore::resources::ResourceType {
        private:
            int imageWidth = 0;
            int imageHeight = 0;
            int channelCount = 0;
            unsigned char* imageData = nullptr;
            bool textureIsLoaded = false;

            ore::resources::Texture texture;

        public:
            void load(const ore::filesystem::path &fileLocation) override;
            void load(ore::resources::Texture alreadyLoadedTexture);

            bool requiresMainThread() override;

            void completeLoadOnMainThread() override;

            void destroy() override;

            bool isLoaded();
            ore::resources::Texture getInstance();
        };
    }
}

