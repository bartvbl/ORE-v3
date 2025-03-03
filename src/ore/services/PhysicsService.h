#pragma once

#include "ore/physics/PhysicsHandle.h"
#include "ore/physics/SimulationType.h"
#include "ore/physics/SimulatedPhysicsObject.h"
#include <ore/sceneGraph/nodes/CoordinateNode.h>
#include <unordered_map>

namespace ore {
    class PhysicsService {
        std::unordered_map<uint32_t, ore::SimulatedPhysicsObject> activePhysicsObjects;
        uint32_t nextHandleID = 0;

    public:
        void init();
        void update();
        ore::PhysicsHandle simulate(ore::scene::GeometryNode *node, ore::SimulationType type);
        void stopSimulation(ore::PhysicsHandle handle);
        void shutdown();
    };
}

