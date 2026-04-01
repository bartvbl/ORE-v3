

#include "GUIWindow.h"
#include "imgui_configured.h"

bool ore::GUIWindow::drawButton(const std::string &label) const {
    return ImGui::Button(label.c_str());
}

void ore::GUIWindow::drawComboBox(const std::vector<std::string> &options, uint32_t& selectedIndex) const {
    const char* combo_preview_value = options.at(selectedIndex).c_str();
    if (ImGui::BeginCombo("", combo_preview_value, 0))
    {
        for (uint32_t i = 0; i < options.size(); i++)
        {
            const bool is_selected = (selectedIndex == i);
            if (ImGui::Selectable(options.at(i).c_str(), is_selected)) {
                selectedIndex = i;
            }

            // Set the initial focus when opening the combo (scrolling + keyboard navigation focus)
            if (is_selected)
                ImGui::SetItemDefaultFocus();
        }
        ImGui::EndCombo();
    }
}

void ore::GUIWindow::drawCheckbox(const std::string &label, bool &isChecked) {
    ImGui::Checkbox(label.c_str(), &isChecked);
}

ore::GUIWindow::GUIWindow(std::string _title, int _initialX, int _initialY, int _width, int _height, bool _titlebarVisible, bool _resizable, bool moveable, bool closeable)
    : title(_title), initialX(_initialX), initialY(_initialY), width(_width), height(_height), titleBarVisible(_titlebarVisible), resizable(_resizable), moveable(moveable), closeable(closeable) {
}

void ore::GUIWindow::drawWindow() {
    if (!isVisible) {
        return;
    }

    if (closeable) {
        ImGui::Begin(title.c_str(), &isWindowOpen);
    } else {
        ImGui::Begin(title.c_str(), nullptr);
    }

    if (!isWindowOpen) {
        isVisible = false;
    }
    drawContents();
    ImGui::End();
}

void ore::GUIWindow::setVisible(bool visible) {
    this->isVisible = visible;
    if (visible) {
        this->isWindowOpen = true;
    }
}
