#pragma once

#include <ore/resources/resourceTypes/ResourceType.h>
#include <ore/resources/resourceTypes/mesh/Mesh.h>
#include <chrono>
#include <ore/gl/vao/GeometryBuffer.h>
#include <ore/sceneGraph/nodes/MeshNode.h>
#include <json.hpp>

namespace ore {
    namespace resources {
        class MeshResource final : public ore::resources::ResourceType {
        private:
            ore::resources::Mesh mesh;
            ore::gl::GeometryBuffer geometryBuffer;

            void loadMDLFile(const ore::filesystem::path &modelFileLocation);
            void loadOBJFile(const ore::filesystem::path &modelFileLocation);
            void buildInstanceTree(ore::SceneNode* node, ore::MeshNode* meshNode, unsigned int* nodeIndex);
        public:
            void load(const ore::filesystem::path &fileLocation) override;

            bool requiresMainThread() override;

            void completeLoadOnMainThread() override;

            void destroy() override;

            ore::MeshNode* createInstance();
        };
    }
}

