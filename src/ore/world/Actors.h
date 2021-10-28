#pragma once

#include <ore/gameObjects/GameObject.h>
#include <vector>

namespace ore {

    class Actors {
    private:
        std::vector<ore::GameObject*> gameObjects;
    public:
        void spawn(ore::GameObject* actor);
        void destroy();
    };
}