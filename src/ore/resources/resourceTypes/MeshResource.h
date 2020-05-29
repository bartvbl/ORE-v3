#pragma once

#include <ore/resources/resourceTypes/ResourceType.h>
#include <ore/resources/resourceTypes/mesh/Mesh.h>
#include <chrono>
#include <ore/gl/vao/GeometryBuffer.h>

namespace ore {
    namespace resources {
        class MeshResource : public ore::resources::ResourceType {
        private:
            std::chrono::time_point<std::chrono::system_clock> fast_start;
            ore::resources::Mesh mesh;
            ore::gl::GeometryBuffer geometryBuffer;
            std::string name;
        public:
            void load(const ore::filesystem::path &fileLocation) override;

            bool requiresMainThread() override;

            void completeLoadOnMainThread() override;

            void destroy() override;
        };
    }
}

