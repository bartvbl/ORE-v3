#define ENABLE_VHACD_IMPLEMENTATION 1
#define VHACD_DISABLE_THREADING 0
#include <Jolt/Jolt.h>

#include <iostream>
#include <cstdio>
#include <stdarg.h>

#include <Jolt/Core/IssueReporting.h>
#include <Jolt/Core/Memory.h>
#include <Jolt/Core/Factory.h>
#include <Jolt/RegisterTypes.h>
#include <Jolt/Math/Real.h>
#include <ore/sceneGraph/nodes/GeometryNode.h>

#include "PhysicsService.h"



using namespace JPH::literals;

static void TraceImpl(const char *inFMT, ...)
{
    va_list list;
    va_start(list, inFMT);
    char buffer[1024];
    vsnprintf(buffer, sizeof(buffer), inFMT, list);
    va_end(list);
    std::cout << buffer << std::endl;
}

#ifdef JPH_ENABLE_ASSERTS
// Callback for asserts, connect this to your own assert handler if you have one
static bool AssertFailedImpl(const char *inExpression, const char *inMessage, const char *inFile, uint inLine)
{
    std::string explanation = inExpression != nullptr ? std::string(inExpression) : "[none]";
    std::string message = inMessage != nullptr ? std::string(inMessage) : "[none]";
    std::string file = inFile != nullptr ? std::string(inFile) : "[unknown]";

    throw std::runtime_error("Physics simulation failed: " + explanation + ", " + message + ", in file " + file + ", line " + std::to_string(inLine));
};
#endif // JPH_ENABLE_ASSERTS

void ore::PhysicsService::init() {
    // Register allocation hook
    JPH::RegisterDefaultAllocator();

    // Install callbacks
    JPH::Trace = TraceImpl;
    JPH_IF_ENABLE_ASSERTS(JPH::AssertFailed = AssertFailedImpl;)

    // Create a factory
    JPH::Factory::sInstance = new JPH::Factory();

    // Register all Jolt physics types
    JPH::RegisterTypes();
}

void ore::PhysicsService::update() {

}

void ore::PhysicsService::shutdown() {
    // Unregisters all types with the factory and cleans up the default material
    JPH::UnregisterTypes();

    // Destroy the factory
    delete JPH::Factory::sInstance;
    JPH::Factory::sInstance = nullptr;
}

ore::PhysicsHandle ore::PhysicsService::simulate(ore::scene::GeometryNode *node, ore::SimulationType type) {
    uint32_t handleForNewObject = nextHandleID;
    nextHandleID++;
    ore::PhysicsHandle handle;
    handle.id = handleForNewObject;
    ore::SimulatedPhysicsObject physicsObject;
    //activePhysicsObjects.insert(handle.id, physicsObject);
    return handle;
}

void ore::PhysicsService::stopSimulation(ore::PhysicsHandle handle) {
    activePhysicsObjects.erase(handle.id);
}
