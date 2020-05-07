#include "GameWorld.h"

void ore::GameWorld::init() {
    resourceCache.init();
    services.soundService.init();
    services.inputService.init();
    services.animationService.init();
    services.aiService.init();
}

void ore::GameWorld::frameTick() {

}
