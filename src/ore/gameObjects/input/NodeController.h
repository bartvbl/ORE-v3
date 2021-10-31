#pragma once

#include <ore/gameObjects/GameObject.h>
#include <ore/sceneGraph/nodes/PerspectiveCamera.h>
#include <ore/services/InputService.h>

namespace ore {
    class NodeController : public ore::GameObject {
    private:
        ore::scene::CoordinateNode* node;
        float movementX = 0;
        float movementY = 0;
        float movementUp = 0;
        float movementDown = 0;
        float lookHorizontal = 0;
        float lookVertical = 0;
    public:
        NodeController(ore::InputService* inputService, ore::scene::CoordinateNode* node) : node(node) {
            inputService->attachListener("moveRight", &movementX);
            inputService->attachListener("moveForward", &movementY);
            inputService->attachListener("moveDownward", &movementDown);
            inputService->attachListener("moveUpward", &movementUp);
            inputService->attachListener("lookRight", &lookHorizontal);
            inputService->attachListener("lookUpward", &lookVertical);
        }

        void update();
    };
}
