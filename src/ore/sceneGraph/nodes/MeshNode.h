#pragma once
#include <ore/sceneGraph/SceneNode.h>

namespace ore {
    class MeshNode : ore::SceneNode {
        std::string getName();

        void preUpdate(ore::RenderState &renderState);
        void postUpdate(ore::RenderState &renderState);

        void preRender(ore::RenderState &renderState);
        void render(ore::RenderState &renderState);
        void postRender(ore::RenderState &renderState);

        std::vector<SceneNode*>* getChildren();

        void destroy();
    };
}
