#pragma once

#include <ore/resources/resourceTypes/ResourceType.h>
#include <ore/gl/shader/ShaderSource.h>
#include <ore/resources/resourceTypes/shader/Shader.h>

namespace ore {
    namespace resources {
        class ShaderResource final : public ore::resources::ResourceType {
        private:
            ore::gl::ShaderSource* shaderSources;
            ore::resources::Shader shader;
            std::string fileName;
        public:
            ore::resources::Shader getInstance();

            void load(const ore::filesystem::path &fileLocation) override;

            bool requiresMainThread() override;

            void completeLoadOnMainThread() override;

            void destroy() override;
        };
    }
}