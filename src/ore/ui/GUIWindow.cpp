

#include "GUIWindow.h"
#include "imgui_configured.h"

bool ore::GUIWindow::drawButton(const std::string &label) const {
    return ImGui::Button(label.c_str());
}

bool ore::GUIWindow::drawComboBox(const std::string& label, const std::vector<std::string> &options, uint32_t& selectedIndex) const {
    const char* combo_preview_value = options.at(selectedIndex).c_str();
    uint32_t originalSelectedIndex = selectedIndex;
    if (ImGui::BeginCombo(label.c_str(), combo_preview_value, 0))
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
    return selectedIndex != originalSelectedIndex;
}

bool ore::GUIWindow::drawCheckbox(const std::string &label, bool &isChecked) {
    return ImGui::Checkbox(label.c_str(), &isChecked);
}

bool ore::GUIWindow::drawTextLineEditor(const std::string &label, std::string &lineToEdit) {
    return ImGui::InputText(label.c_str(), &lineToEdit);
}

bool ore::GUIWindow::drawDragFloat3(const std::string &label, glm::vec3 *vecToEdit) {
    float tempArray[3] = {vecToEdit->x, vecToEdit->y, vecToEdit->z};
    bool modified = ImGui::DragFloat3(label.c_str(), tempArray, 0.01);
    vecToEdit->x = tempArray[0];
    vecToEdit->y = tempArray[1];
    vecToEdit->z = tempArray[2];
    return modified;
}

bool ore::GUIWindow::drawDragFloat2(const std::string &label, glm::vec2 *vecToEdit) {
    float tempArray[2] = {vecToEdit->x, vecToEdit->y};
    bool modified = ImGui::DragFloat2(label.c_str(), tempArray, 0.01);
    vecToEdit->x = tempArray[0];
    vecToEdit->y = tempArray[1];
    return modified;
}

bool ore::GUIWindow::drawDragFloat(const std::string &label, float *floatToEdit) {
    return ImGui::DragFloat(label.c_str(), floatToEdit, 0.01);
}

bool ore::GUIWindow::drawSelectColour(const std::string &label, glm::vec3 *colourToEdit) {
    float tempArray[3] = {colourToEdit->x, colourToEdit->y, colourToEdit->z};
    bool modified = ImGui::ColorEdit3(label.c_str(), tempArray);
    colourToEdit->x = tempArray[0];
    colourToEdit->y = tempArray[1];
    colourToEdit->z = tempArray[2];
    return modified;
}

void ore::GUIWindow::drawText(const std::string &text) {
    ImGui::Text(text.c_str());
}

void ore::GUIWindow::keepSameLine() {
    ImGui::SameLine();
}

void ore::GUIWindow::drawSeparator(const std::string &label) {
    if (!label.empty()) {
        ImGui::SeparatorText(label.c_str());
    } else {
        ImGui::Separator();
    }
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

bool ore::GUIWindow::isClosed() {
    return !isWindowOpen;
}

void ore::GUIWindow::setVisible(bool visible) {
    this->isVisible = visible;
    if (visible) {
        this->isWindowOpen = true;
    }
}
