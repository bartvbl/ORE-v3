#pragma once

#include <ore/sceneGraph/SceneNode.h>
#include <GLFW/glfw3.h>

namespace ore {
    namespace RenderPass {
        void render(ore::SceneNode* rootNode, GLFWwindow* window);
    }
}

