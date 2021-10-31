#include "GameWorld.h"

void ore::GameWorld::init(GLFWwindow* window) {
    resourceCache.init(window);
    services.soundService.init();
    services.inputService.init(window);
    services.animationService.init();
    services.aiService.init();
    services.configService.init();
}

void ore::GameWorld::frameTick() {
    resourceCache.flushMainThreadCompletions();
    services.inputService.tick();
    actors.update();
}

void ore::GameWorld::shutdown() {
    resourceCache.shutdown();
}