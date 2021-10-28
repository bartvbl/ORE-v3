#pragma once

#include <ore/gl/render/RenderState.h>
#include <vector>
#include <string>

namespace ore {
    class SceneNode {
    public:
        virtual std::string getName() = 0;

        virtual void update(ore::RenderState &renderState);

        virtual void preRender(ore::RenderState &renderState);

        virtual void render(ore::RenderState &renderState);

        virtual void postRender(ore::RenderState &renderState);

        virtual std::vector<SceneNode*>* getChildren() = 0;

        virtual void destroy();
    };
}
