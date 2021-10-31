#include "Actors.h"

void ore::Actors::spawn(ore::GameObject *actor) {
    gameObjects.push_back(actor);
}

void ore::Actors::destroy() {

}

void ore::Actors::update() {
    for(ore::GameObject* object : gameObjects) {
        object->update();
    }
}
