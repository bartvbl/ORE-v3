#include <GLFW/glfw3.h>
#include "InputService.h"

void ore::InputService::init(GLFWwindow* window) {
    this->gameWindow = window;
}

void ore::InputService::tick() {
    glfwPollEvents();


}

void ore::InputService::addKeyBindingsFromFile(ore::filesystem::path bindingsFile) {

}

void ore::InputService::addKeyBinding(ore::input::InputType key, ore::input::InputMappingType mappingType, ore::input::InputEventTriggerType triggerType, std::string binding) {
    KeyMapping mapping;
    mapping.inputType = key;
    mapping.mappingName = binding;
    mapping.mappingType = mappingType;
    mapping.triggerType = triggerType;
    keyBindingMap[key].push_back(mapping);
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
    const std::string keyMappingContainingListener = listenerRegistrations.at(reference);
    listenerRegistrations.erase(reference);
    std::vector<Listener>& listeners = listenerMap.at(keyMappingContainingListener);
    for(unsigned int i = 0; i < listeners.size(); i++) {
        if(listeners.at(i).id == reference) {
            listeners.erase(listeners.begin() + i);
            return;
        }
    }
    throw std::runtime_error("The listener with type " + keyMappingContainingListener + " and ID " + std::to_string(reference) + " could not be found.");
}


