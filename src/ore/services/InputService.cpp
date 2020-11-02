#include <GLFW/glfw3.h>
#include "InputService.h"

void ore::InputService::init(GLFWwindow* window) {
    this->gameWindow = window;
}

void ore::InputService::tick() {
    glfwPollEvents();

    // Use escape key for terminating the GLFW window
    if (glfwGetKey(gameWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(gameWindow, true);
    }

}

void ore::InputService::addKeyBindingsFromFile(ore::filesystem::path bindingsFile) {

}

void ore::InputService::addKeyBinding(ore::input::InputType key, ore::input::InputMappingType mappingType, ore::input::InputEventTriggerType triggerType, std::string binding) {

}

void ore::InputService::saveKeyBindingsToFile(ore::filesystem::path bindingsFile) {

}

unsigned int ore::InputService::attachListener(std::string &keyMappingName, ore::InputService::Listener listener) {
    unsigned int nextID = nextListenerID;
    nextListenerID++;
    listener.id = nextID;

    listenerRegistrations[nextID] = keyMappingName;
    listenerMap[keyMappingName].push_back(listener);

    return nextID;
}


unsigned int ore::InputService::attachListener(std::string keyMappingName, bool *target) {
    Listener listener;
    listener.targetType = PointerType::BOOL;
    listener.target.asBoolean = target;
    return attachListener(keyMappingName, listener);
}

unsigned int ore::InputService::attachListener(std::string keyMappingName, float *target) {
    Listener listener;
    listener.targetType = PointerType::FLOAT;
    listener.target.asFloat = target;
    return attachListener(keyMappingName, listener);
}

unsigned int ore::InputService::attachListener(std::string keyMappingName, int *target) {
    Listener listener;
    listener.targetType = PointerType::INT;
    listener.target.asInt = target;
    return attachListener(keyMappingName, listener);
}

void ore::InputService::detachListener(unsigned int reference) {

}


