

#include "GUIRootNode.h"

#include <algorithm>
#include <stdexcept>

#include "nuklear_glfw_gl4.h"

#define MAX_VERTEX_BUFFER (512 * 1024)
#define MAX_ELEMENT_BUFFER (128 * 1024)

void ore::GUIRootNode::init(GLFWwindow* _window) {
    window = _window;
    context = nk_glfw3_init(_window, NK_GLFW3_INSTALL_CALLBACKS, MAX_VERTEX_BUFFER, MAX_ELEMENT_BUFFER);

    fontCache.initialize();
    fontCache.setFont(context, ore::ui::Font::arial, 16);
}

std::string ore::GUIRootNode::getName() {
    return "GUI root node";
}

std::vector<ore::SceneNode *>* ore::GUIRootNode::getChildren() {
    return &noChildren;
}

void ore::GUIRootNode::addWindow(ore::GUIWindow *window) {
    windows.push_back(window);
}

void ore::GUIRootNode::removeWindow(ore::GUIWindow *window) {
    std::vector<ore::GUIWindow*>::iterator it = std::find(windows.begin(), windows.end(), window);
    if (it != windows.end()) {
        windows.erase(it);
    } else {
        throw std::out_of_range("Requested a window to be removed, but it was not found.");
    }
}

void ore::GUIRootNode::render(ore::RenderState &renderState) {
    nk_glfw3_new_frame(renderState.window.width, renderState.window.height);

    for (ore::GUIWindow* win : windows) {
        fontCache.setFont(context, ore::ui::Font::arial, 18);
        win->drawWindow(context);
    }

    nk_glfw3_render(NK_ANTI_ALIASING_ON);
}


