#pragma once

#include "SimulationType.h"
#include "ore/sceneGraph/nodes/CoordinateNode.h"

namespace ore {
    struct SimulatedPhysicsObject {
        ore::SimulationType type = ore::SimulationType::FIXED_IN_SPACE;
        ore::scene::CoordinateNode *target = nullptr;
    };
}