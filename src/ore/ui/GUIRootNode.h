#pragma once
#include <unordered_map>

#include "GUIWindow.h"
#include "ore/sceneGraph/nodes/ContainerNode.h"
#include <GLFW/glfw3.h>

#include "FontCache.h"
#include "nuklear_configured.h"

namespace ore {
    class GUIRootNode : public ore::SceneNode {
        std::vector<ore::GUIWindow*> windows;
        GLFWwindow* window = nullptr;
        nk_context* context;
        ore::ui::FontCache fontCache;

    public:
        void init(GLFWwindow *_window);

        virtual std::string getName() override;

        virtual std::vector<SceneNode*>* getChildren() override;

        void addWindow(ore::GUIWindow* window);
        void removeWindow(ore::GUIWindow* window);

        virtual void render(ore::RenderState &renderState) override;
    };
}
