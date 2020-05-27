#include "GameWorld.h"

void ore::GameWorld::init(GLFWwindow* window) {
    resourceCache.init(window);
    services.soundService.init();
    services.inputService.init();
    services.animationService.init();
    services.aiService.init();
}

void ore::GameWorld::frameTick() {

}

void ore::GameWorld::shutdown() {
    resourceCache.shutdown();
}