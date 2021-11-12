#pragma once

#include <ore/sceneGraph/nodes/ContainerNode.h>
#include <ore/gl/lighting/Light.h>
#include <ore/core/Constants.h>
#include <array>

namespace ore {
    namespace scene {
        class LightNode : public ore::scene::ContainerNode {
        private:
            std::array<ore::gl::Light, ore::MAX_LIGHT_SOURCES> lightSources;
            unsigned int lightSourceCount = 0;
        public:
            void preRender(ore::RenderState &state) override;

            void render(ore::RenderState &state) override;

            void addLight(ore::gl::Light &light);

            void clearLights();
        };
    }
}