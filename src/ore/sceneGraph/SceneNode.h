#pragma once

#include <ore/gl/render/RenderState.h>
#include <vector>
#include <string>

namespace ore {
    class SceneNode {
    public:
        virtual std::string getName() = 0;

        virtual void preUpdate(ore::RenderState &renderState) = 0;
        virtual void postUpdate(ore::RenderState &renderState) = 0;

        virtual void preRender(ore::RenderState &renderState) = 0;
        virtual void render(ore::RenderState &renderState) = 0;
        virtual void postRender(ore::RenderState &renderState) = 0;

        virtual std::vector<SceneNode>* getChildren() = 0;

        virtual void destroy() = 0;
    };
}
