#pragma once

#include <ore/gl/RenderState.h>
#include <vector>

namespace ore {
    class SceneNode {
    public:
        virtual void preRender(ore::RenderState &renderState) = 0;
        virtual void render(ore::RenderState &renderState) = 0;
        virtual void postRender(ore::RenderState &renderState) = 0;

        virtual std::vector<SceneNode>* getChildren() = 0;

        virtual void destroy() = 0;
    };
}
