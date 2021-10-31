//
// Created by bart on 31.10.2021.
//

#include "BuiltinEngineKeybinds.h"

void ore::BuiltinEngineKeybinds::update() {
    if(quitRequested) {
        services->configService.gameShouldShutdown = true;
    }
}
