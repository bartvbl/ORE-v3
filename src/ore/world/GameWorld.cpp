#include "GameWorld.h"
#include <ore/gameObjects/input/BuiltinEngineKeybinds.h>

void ore::GameWorld::init(GLFWwindow* _window) {
    resourceCache.init(_window);
    services.configService.init();
    services.soundService.init();
    services.inputService.init(_window);
    services.animationService.init();
    services.aiService.init();
    services.physicsService.init();
    this->window = _window;

    actors.spawn(new ore::BuiltinEngineKeybinds(&services));
}

void ore::GameWorld::frameTick() {
    resourceCache.flushMainThreadCompletions();
    services.inputService.tick();
    services.animationService.update();
    services.physicsService.update();
    actors.update();
}

void ore::GameWorld::shutdown() {
    resourceCache.shutdown();
    services.physicsService.shutdown();
}