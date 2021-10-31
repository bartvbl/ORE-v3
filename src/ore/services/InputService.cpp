#include <GLFW/glfw3.h>
#include <iostream>
#include <g3log/g3log.hpp>
#include <json.hpp>
#include <fstream>
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



void ore::InputService::fireInputEvent(const ore::InputService::KeyMapping &mapping, float previousState, float currentState) {
    std::vector<Listener>* listeners = &listenerMap[mapping.mappingName];

    float eventValue = currentState;
    if(mapping.mappingType == input::InputMappingType::RELATIVE) {
        eventValue = currentState - previousState;
    }
    bool eventBoolValue = eventValue != 0;
    int eventIntValue = (int) currentState;

    for(Listener& listener : *listeners) {
        switch(listener.targetType) {
            case PointerType::BOOL:
                *listener.target.asBoolean = eventBoolValue;
                break;
            case PointerType::FLOAT:
                *listener.target.asFloat = eventValue;
                break;
            case PointerType::INT:
                *listener.target.asInt = eventIntValue;
                break;
        }
    }
}

void ore::InputService::resetListenerValues(const ore::InputService::KeyMapping &mapping) {
    std::vector<Listener>* listeners = &listenerMap[mapping.mappingName];

    for(Listener& listener : *listeners) {
        switch(listener.targetType) {
            case PointerType::BOOL:
                *listener.target.asBoolean = false;
                break;
            case PointerType::FLOAT:
                *listener.target.asFloat = 0;
                break;
            case PointerType::INT:
                *listener.target.asInt = 0;
                break;
        }
    }
}

void ore::InputService::handleInputState(ore::input::InputType type, float currentState, const std::vector<KeyMapping> *mappings) {
    auto entry = previousInputStateMap.find(type);
    if(entry == previousInputStateMap.end()) {
        previousInputStateMap[type] = 0;
        entry = previousInputStateMap.find(type);
    }

    float previousState = entry->second;

    bool onChange = previousState != currentState;
    bool onPress = currentState != 0 && previousState == 0;
    bool onHold = currentState != 0;
    bool onRelease = currentState == 0 && previousState != 0;
    bool onIncreasing = currentState > previousState;
    bool onDecreasing = currentState < previousState;

    for(const KeyMapping& mapping : *mappings) {
        switch(mapping.triggerType) {
            case input::InputEventTriggerType::ON_FRAME_START:
                fireInputEvent(mapping, previousState, currentState);
                break;
            case input::InputEventTriggerType::ON_CHANGE:
                if(onChange) {
                    fireInputEvent(mapping, 0, 1);
                }
                break;
            case input::InputEventTriggerType::ON_PRESS:
                if(onPress) {
                    fireInputEvent(mapping, 0, 1);
                }
                break;
            case input::InputEventTriggerType::ON_HOLD:
                if(onHold) {
                    fireInputEvent(mapping, previousState, currentState);
                }
                break;
            case input::InputEventTriggerType::ON_RELEASE:
                if(onRelease) {
                    fireInputEvent(mapping, 0, 1);
                }
                break;
            case input::InputEventTriggerType::ON_INCREASING:
                if(onIncreasing) {
                    fireInputEvent(mapping, previousState, currentState);
                }
                break;
            case input::InputEventTriggerType::ON_DECREASING:
                if(onDecreasing) {
                    fireInputEvent(mapping, previousState, currentState);
                }
                break;
        }
    }

    entry->second = currentState;
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

    std::array<unsigned char, 16> controllerButtons;
    std::array<float, 16> controllerAxes;
    bool controllerIsPresent = glfwJoystickPresent(GLFW_JOYSTICK_1);
    if(controllerIsPresent) {
        int count;
        const unsigned char* buttonState = glfwGetJoystickButtons(GLFW_JOYSTICK_1, &count);
        for(int i = 0; i < count; i++) {
            controllerButtons.at(i) = buttonState[i];
        }

        const float* axesState = glfwGetJoystickAxes(GLFW_JOYSTICK_1, &count);
        for(int i = 0; i < count; i++) {
            controllerAxes.at(i) = axesState[i];
        }
    }

    // Reset listener values
    for(const std::pair<std::string, std::vector<Listener>> registrations : listenerMap) {
        for(const Listener &listener : registrations.second) {
            switch(listener.targetType) {
                case PointerType::BOOL:
                    *listener.target.asBoolean = false;
                    break;
                case PointerType::FLOAT:
                    *listener.target.asFloat = 0;
                    break;
                case PointerType::INT:
                    *listener.target.asInt = 0;
                    break;
            }
        }
    }

    for(const std::pair<const ore::input::InputType, std::vector<KeyMapping>> &entry : keyBindingMap) {
        // Obtain state of the input
        ore::input::InputType type = entry.first;
        float inputState = 0;

        // Keyboard bindings
        if(int(type) >= int(ore::input::KEYBOARD_START) && int(type) <= int(ore::input::KEYBOARD_END)) {
            bool keyState = glfwGetKey(gameWindow, ore::input::toGLFWEnum(type)) == GLFW_PRESS;
            inputState = keyState ? 1.0 : 0.0;

            handleInputState(type, inputState, &entry.second);

        // Mouse bindings
        } else if(int(type) >= int(ore::input::MOUSE_BUTTON_START) && int(type) <= int(ore::input::MOUSE_BUTTON_END)) {
            bool buttonState = glfwGetMouseButton(gameWindow, ore::input::toGLFWEnum(type)) == GLFW_PRESS;
            inputState = buttonState ? 1.0 : 0.0;

            handleInputState(type, inputState, &entry.second);

        } else if(int(type) >= int(ore::input::MOUSE_AXIS_START) && int(type) <= int(ore::input::MOUSE_AXIS_END)) {
            if(type == ore::input::InputType::MOUSE_AXIS_HORIZONTAL) {
                double normalisedMousePosition = mouseX / double(windowWidth);
                inputState = float(normalisedMousePosition);
                handleInputState(type, inputState, &entry.second);
            } else if(type == ore::input::InputType::MOUSE_AXIS_VERTICAL) {
                double normalisedMousePosition = mouseY / double(windowHeight);
                inputState = float(normalisedMousePosition);
                handleInputState(type, inputState, &entry.second);
            } else if(type == ore::input::InputType::MOUSE_AXIS_SCROLL) {
                inputState = float(ore::input::yScrollOffset);
                handleInputState(type, inputState, &entry.second);
            }

        // Controller bindings
        } else if(int(type) >= int(ore::input::CONTROLLER_BUTTON_START) && int(type) <= int(ore::input::CONTROLLER_BUTTON_END)) {
            if(controllerIsPresent) {
                int buttonIndex = int(type) - int(ore::input::CONTROLLER_BUTTON_START);
                bool buttonState = controllerButtons.at(buttonIndex);
                inputState = buttonState ? 1.0 : 0.0;
                handleInputState(type, inputState, &entry.second);
            }
        } else if(int(type) >= int(ore::input::CONTROLLER_AXIS_START) && int(type) <= int(ore::input::CONTROLLER_AXIS_END)) {
            if(controllerIsPresent) {
                int axisIndex = int(type) - int(ore::input::CONTROLLER_AXIS_START);
                float axisState = controllerAxes.at(axisIndex);
                if(type == input::InputType::CONTROLLER_AXIS_LEFT_TRIGGER ||
                   type == input::InputType::CONTROLLER_AXIS_RIGHT_TRIGGER) {
                    // triggers vary between -1 and 1, therefore we map it from 0 to 1
                    axisState = 0.5f * (axisState + 1);
                }
                std::cout << int(type) << ": " << axisState << std::endl;
                handleInputState(type, axisState, &entry.second);
            }
        }
    }
}

void ore::InputService::addKeyBindingsFromFile(ore::filesystem::path bindingsFile) {
    if(!ore::filesystem::exists(bindingsFile)) {
        LOG(WARNING) << "The input configuration file at " << bindingsFile.string() << " was not found, and will be ignored." << std::endl;
        return;
    }
    LOG(INFO) << "Adding keybindings from file " << bindingsFile.string() << std::endl;

    nlohmann::json bindingsFileContents;
    std::ifstream fileStream(bindingsFile);
    try {
        fileStream >> bindingsFileContents;
    } catch(nlohmann::detail::exception &e) {
        LOG(FATAL) << "Failed to load key bindings file located at " << bindingsFile << std::endl << "Reason:" << std::endl << e.what() << std::endl;
        throw std::runtime_error("Resource failed to load.");
    }
    fileStream.close();

    for(const nlohmann::json& binding : bindingsFileContents["bindings"]) {
        std::string inputTypeString = std::string(binding["key"]);
        ore::input::InputType inputType = input::parseInputType(inputTypeString);

        std::string keyBinding = binding["binding"];

        ore::input::InputMappingType mappingType = binding["mapping"] == "absolute" ?
                ore::input::InputMappingType::ABSOLUTE : ore::input::InputMappingType::RELATIVE;

        ore::input::InputEventTriggerType triggerType = ore::input::parseEventTriggerType(binding["trigger"]);

        addKeyBinding(inputType, mappingType, triggerType, keyBinding);
    }
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

void ore::InputService::addKeyBindingsFromFiles(std::vector<ore::filesystem::path> &configurationFilePaths) {
    for(const ore::filesystem::path& path : configurationFilePaths) {
        addKeyBindingsFromFile(path);
    }
}









