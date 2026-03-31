

#pragma once
#include "nuklear_configured.h"

namespace ore {
    class GUIWindow {
    public:
        virtual void drawContents() = 0;

        void drawWindow(nk_context * context);
    };
}
