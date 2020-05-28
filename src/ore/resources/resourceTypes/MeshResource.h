#pragma once

#include <ore/resources/resourceTypes/ResourceType.h>
#include <ore/resources/resourceTypes/mesh/Mesh.h>

namespace ore {
    namespace resources {
        class MeshResource : public ore::resources::ResourceType {
        private:
            ore::resources::Mesh mesh;
        public:
            void load(const ore::filesystem::path &fileLocation) override;

            bool requiresMainThread() override;

            void completeLoadOnMainThread() override;

            void destroy() override;
        };
    }
}

