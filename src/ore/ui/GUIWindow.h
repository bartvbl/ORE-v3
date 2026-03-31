

#pragma once
#include <vector>

#include "nuklear_configured.h"
#include "ore/sceneGraph/SceneNode.h"

namespace ore {
    class GUIWindow {
        std::string title;
        int initialX = 0;
        int initialY = 0;
        int width = 0;
        int height = 0;
        bool isVisible = true;
        bool titleBarVisible = true;
        bool resizable = true;
        bool moveable = true;
        nk_context* context = nullptr;
    protected:
        void newRow(uint32_t width, uint32_t height, uint32_t columns) const;
        bool drawButton(const std::string &label) const;
        void drawComboBox(const std::vector<std::string>& options, uint32_t& selectedIndex) const;

    public:
        GUIWindow(std::string _title, int _initialX, int _initialY, int _width, int _height, bool _titlebarVisible = true, bool _resizable = true, bool moveable = true);
        virtual ~GUIWindow() = default;

        virtual void drawContents() = 0;

        void drawWindow(nk_context* context);
        void setVisible(bool visible);
    };
}
