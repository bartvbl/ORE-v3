#pragma once

#include <ore/gl/render/RenderState.h>
#include <vector>
#include <string>

namespace ore {
    class SceneNode {
    public:
        virtual std::string getName() = 0;

        void update(ore::RenderState &renderState);

        void render(ore::RenderState &renderState);

        virtual std::vector<SceneNode*>* getChildren() = 0;

        void destroy();
    };
}
