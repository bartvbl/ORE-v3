#pragma once
#include <ore/utilities/filesystem.h>
#include <ore/services/input/InputType.h>
#include <ore/services/input/InputMappingType.h>
#include <unordered_map>
#include <ore/services/input/InputEventTriggerType.h>
#include <GLFW/glfw3.h>

namespace ore {
    namespace input {
        static double xScrollOffset;
        static double yScrollOffset;
    }

    class InputService {
    private:

        GLFWwindow* gameWindow;

        unsigned int nextListenerID = 0;
        unsigned int targetJoystick = GLFW_JOYSTICK_1;
        bool joystickActive = false;
        std::chrono::time_point<std::chrono::steady_clock> lastJoystickCheck;
        static constexpr double secondsBetweenJoystickChecks = 1;

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
            ore::input::InputEventTriggerType triggerType;
            std::string mappingName;
        };


        std::unordered_map<ore::input::InputType, float> previousInputStateMap;
        std::unordered_map<unsigned int, std::string> listenerRegistrations;
        std::unordered_map<std::string, std::vector<Listener>> listenerMap;

        std::unordered_map<ore::input::InputType, std::vector<KeyMapping>> keyBindingMap;

        unsigned int attachListener(std::string &keyMappingName, Listener listener);
        static void scrollCallback(GLFWwindow* window, double xOffset, double yOffset);
        void runJoystickCheck(bool force = false);

        void handleInputState(input::InputType type, float state, const std::vector<KeyMapping> *mappings);

        void fireInputEvent(const KeyMapping &mapping, float previousState, float currentState);
        void resetListenerValues(const KeyMapping &mapping);

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

        void addKeyBindingsFromFiles(std::vector<filesystem::path> &configurationFilePaths);



    };
}

