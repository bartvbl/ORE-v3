#pragma once
#include <ore/utilities/filesystem.h>
#include <ore/services/input/InputType.h>
#include <ore/services/input/InputMappingType.h>
#include <unordered_map>
#include <ore/services/input/InputEventTriggerType.h>

namespace ore {
    class InputService {
    private:
        GLFWwindow* gameWindow;

        unsigned int nextListenerID = 0;

        enum class PointerType {
            BOOL, FLOAT, INT
        };

        struct Listener {
            unsigned int id;

            PointerType targetType;
            union {
                bool* asBoolean;
                float* asFloat;
                int* asInt;
            } target;
        };

        struct KeyMapping {
            ore::input::InputType inputType;
            ore::input::InputMappingType mappingType;
            std::string mappingName;
        };

        std::unordered_map<unsigned int, std::string> listenerRegistrations;
        std::unordered_map<std::string, std::vector<Listener>> listenerMap;

        std::unordered_map<ore::input::InputType, std::vector<KeyMapping>> keyBindingMap;

        unsigned int attachListener(std::string &keyMappingName, Listener listener);

    public:
        void init(GLFWwindow* gameWindow);
        void tick();

        void addKeyBindingsFromFile(ore::filesystem::path bindingsFile);
        void addKeyBinding(ore::input::InputType key, ore::input::InputMappingType mappingType, ore::input::InputEventTriggerType triggerType, std::string binding);
        void saveKeyBindingsToFile(ore::filesystem::path bindingsFile);

        unsigned int attachListener(std::string keyMappingName, bool* target);
        unsigned int attachListener(std::string keyMappingName, float* target);
        unsigned int attachListener(std::string keyMappingName, int* target);

        void detachListener(unsigned int reference);
        void removeKeyBinding(ore::input::InputType type);
        void removeAllKeyBindings();
    };
}

