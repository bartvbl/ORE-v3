

#include "GUIRootNode.h"

#include <algorithm>
#include <stdexcept>

#include "imgui_configured.h"

#define MAX_VERTEX_BUFFER (512 * 1024)
#define MAX_ELEMENT_BUFFER (128 * 1024)

void ore::GUIRootNode::init(GLFWwindow* _window) {
    window = _window;

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
    //io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;         // IF using Docking Branch

    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(_window, true);          // Second param install_callback=true will install GLFW callbacks and chain to existing ones.
    ImGui_ImplOpenGL3_Init();

    //fontCache.initialize();
    //fontCache.setFont(context, ore::ui::Font::arial, 16);
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
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
    //ImGui::ShowDemoWindow(); // Show demo window! :)

    for (ore::GUIWindow* win : windows) {
        win->drawWindow();
    }

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}


