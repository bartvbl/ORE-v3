

#pragma once
#include <vector>

#include "ore/sceneGraph/SceneNode.h"

namespace ore {
    class GUIWindow {
        std::string title;
        int initialX = 0;
        int initialY = 0;
        int width = 0;
        int height = 0;
        bool isVisible = true;
        bool isWindowOpen = true;
        bool titleBarVisible = true;
        bool resizable = true;
        bool moveable = true;
        bool closeable = true;

    protected:
        bool drawButton(const std::string &label) const;
        bool drawComboBox(const std::string& label, const std::vector<std::string>& options, uint32_t& selectedIndex) const;
        bool drawCheckbox(const std::string& label, bool& isChecked);
        bool drawTextLineEditor(const std::string& label, std::string& lineToEdit);
        bool drawDragFloat3(const std::string& label, glm::vec3* vecToEdit);
        bool drawDragFloat2(const std::string& label, glm::vec2* vecToEdit);
        bool drawDragFloat(const std::string& label, float* floatToEdit);
        void drawText(const std::string& text);
        void keepSameLine();

    public:
        GUIWindow(std::string _title, int _initialX, int _initialY, int _width, int _height, bool _titlebarVisible = true, bool _resizable = true, bool moveable = true, bool closeable = true);
        virtual ~GUIWindow() = default;

        virtual void drawContents() = 0;

        void drawWindow();
        bool isClosed();
        void setVisible(bool visible);
    };
}
