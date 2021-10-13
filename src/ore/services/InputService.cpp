#include <GLFW/glfw3.h>
#include <iostream>
#include "InputService.h"

void ore::InputService::scrollCallback(GLFWwindow *window, double xOffset, double yOffset) {
    ore::input::xScrollOffset += xOffset;
    ore::input::yScrollOffset += yOffset;
}

void ore::InputService::init(GLFWwindow* window) {
    this->gameWindow = window;
    ore::input::xScrollOffset = 0;
    ore::input::yScrollOffset = 0;
    glfwSetScrollCallback(window, this->scrollCallback);
}

void ore::InputService::tick() {
    glfwPollEvents();

    // Fetch updated window and mouse positions
    double mouseX;
    double mouseY;
    glfwGetCursorPos(gameWindow, &mouseX, &mouseY);

    int windowWidth;
    int windowHeight;
    glfwGetWindowSize(gameWindow, &windowWidth, &windowHeight);

    // Move mouse origin to window bottom left
    mouseY = double(windowHeight) - mouseY;

    GLFWgamepadstate gamepadState;
    bool controllerIsPresent = glfwJoystickPresent(GLFW_JOYSTICK_1) && glfwJoystickIsGamepad(GLFW_JOYSTICK_1);
    if(controllerIsPresent) {
        glfwGetGamepadState(GLFW_JOYSTICK_1, &gamepadState);
    }

    for(const std::pair<const ore::input::InputType, std::vector<KeyMapping>> &entry : keyBindingMap) {
        // Obtain state of the input
        ore::input::InputType type = entry.first;
        float inputState = 0;

        // Keyboard bindings
        if(int(type) >= int(ore::input::KEYBOARD_START) && int(type) <= int(ore::input::KEYBOARD_END)) {
            bool keyState = glfwGetKey(gameWindow, ore::input::toGLFWEnum(type)) == GLFW_PRESS;
            inputState = keyState ? 1.0 : 0.0;

        // Mouse bindings
        } else if(int(type) >= int(ore::input::MOUSE_BUTTON_START) && int(type) <= int(ore::input::MOUSE_BUTTON_END)) {
            bool buttonState = glfwGetMouseButton(gameWindow, ore::input::toGLFWEnum(type)) == GLFW_PRESS;
            inputState = buttonState ? 1.0 : 0.0;
        } else if(int(type) >= int(ore::input::MOUSE_AXIS_START) && int(type) <= int(ore::input::MOUSE_AXIS_END)) {
            if(type == ore::input::InputType::MOUSE_AXIS_HORIZONTAL) {
                double normalisedMousePosition = mouseX / double(windowWidth);
                inputState = float(normalisedMousePosition);
            } else if(type == ore::input::InputType::MOUSE_AXIS_VERTICAL) {
                double normalisedMousePosition = mouseY / double(windowHeight);
                inputState = float(normalisedMousePosition);
            } else if(type == ore::input::InputType::MOUSE_AXIS_SCROLL) {
                inputState = float(ore::input::yScrollOffset);
            }

        // Controller bindings
        } else if(int(type) >= int(ore::input::CONTROLLER_BUTTON_START) && int(type) <= int(ore::input::CONTROLLER_BUTTON_END)) {
            if(controllerIsPresent) {
                bool buttonState = gamepadState.buttons[int(type) - int(ore::input::CONTROLLER_BUTTON_START)];
                inputState = buttonState ? 1.0 : 0.0;
            }
        }
    }
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




