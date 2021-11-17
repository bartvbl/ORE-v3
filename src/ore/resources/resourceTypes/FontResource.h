#pragma once

#include <ore/resources/resourceTypes/ResourceType.h>
#include <ore/gl/font/Font.h>
#include <ore/sceneGraph/nodes/TextNode.h>

namespace ore {
    namespace resources {
        class FontResource final : public ore::resources::ResourceType {
        private:
            ore::gl::Font* font = nullptr;
            std::vector<unsigned char> characterTextureDataRGBA;
            unsigned int fontTextureWidthPixels = 0;
            unsigned int fontTextureHeightPixels = 0;
            std::unordered_map<unsigned int, std::vector<ore::gl::FontCharacter>> characterMap;

        public:
            void load(const ore::filesystem::path &fileLocation) override;

            bool requiresMainThread() override;

            void completeLoadOnMainThread() override;

            void destroy() override;

            ore::scene::TextNode getInstance();
        };
    }
}

