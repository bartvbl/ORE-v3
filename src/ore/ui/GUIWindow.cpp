

#include "GUIWindow.h"

void ore::GUIWindow::newRow(uint32_t cellWidth, uint32_t columnHeight, uint32_t columns) const {
    nk_layout_row_static(context, columnHeight, cellWidth, columns);
}

bool ore::GUIWindow::drawButton(const std::string &label) const {
    return nk_button_label(context, label.c_str());
}

void ore::GUIWindow::drawComboBox(const std::vector<std::string> &options, uint32_t& selectedIndex) const {
    if (nk_combo_begin_label(context, options.at(selectedIndex).c_str(), nk_vec2(nk_widget_width(context), 200))) {
        nk_layout_row_dynamic(context, 35, 1);
        for(unsigned int i = 0; i < options.size(); i++) {
            if (nk_combo_item_label(context, options.at(i).c_str(), NK_TEXT_LEFT)) {
                // selection changed
                selectedIndex = i;
            }
        }
        nk_combo_end(context);
    }
}

ore::GUIWindow::GUIWindow(std::string _title, int _initialX, int _initialY, int _width, int _height)
    : title(_title), initialX(_initialX), initialY(_initialY), width(_width), height(_height) {
}

void ore::GUIWindow::drawWindow(nk_context *context) {
    this->context = context;
    if (nk_begin(context, title.c_str(), nk_rect(initialX, initialY, width, height),
        NK_WINDOW_BORDER|NK_WINDOW_MOVABLE|NK_WINDOW_TITLE|NK_WINDOW_SCALABLE)) {

        drawContents();

        nk_end(context);
        }
}