#pragma once

#include <ore/resouces/loadScreen/LoadScreenRenderer.h>

namespace ore {
    class GameState {

    public:
        virtual void update() = 0;
        virtual void set(ore::resources::ResourceCache* cache) = 0;
        virtual void unset() = 0;
    };
}