#pragma once

#include <string>

namespace ore {
    namespace input {
        enum class InputType {
            // Keyboard
            KEY_A = 0,
            KEY_B = 1,
            KEY_C = 2,
            KEY_D = 3,
            KEY_E = 4,
            KEY_F = 5,
            KEY_G = 6,
            KEY_H = 7,
            KEY_I = 8,
            KEY_J = 9,
            KEY_K = 10,
            KEY_L = 11,
            KEY_M = 12,
            KEY_N = 13,
            KEY_O = 14,
            KEY_P = 15,
            KEY_Q = 16,
            KEY_R = 17,
            KEY_S = 18,
            KEY_T = 19,
            KEY_U = 20,
            KEY_V = 21,
            KEY_W = 22,
            KEY_X = 23,
            KEY_Y = 24,
            KEY_Z = 25,

            KEY_0 = 26,
            KEY_1 = 27,
            KEY_2 = 28,
            KEY_3 = 29,
            KEY_4 = 30,
            KEY_5 = 31,
            KEY_6 = 32,
            KEY_7 = 33,
            KEY_8 = 34,
            KEY_9 = 35,

            KEY_F1 = 36,
            KEY_F2 = 37,
            KEY_F3 = 38,
            KEY_F4 = 39,
            KEY_F5 = 40,
            KEY_F6 = 41,
            KEY_F7 = 42,
            KEY_F8 = 43,
            KEY_F9 = 44,
            KEY_F10 = 45,
            KEY_F11 = 46,
            KEY_F12 = 47,
            KEY_F13 = 48,
            KEY_F14 = 49,
            KEY_F15 = 50,
            KEY_F16 = 51,
            KEY_F17 = 52,
            KEY_F18 = 53,
            KEY_F19 = 54,
            KEY_F20 = 55,
            KEY_F21 = 56,
            KEY_F22 = 57,
            KEY_F23 = 58,
            KEY_F24 = 59,
            KEY_F25 = 60,

            KEY_LEFT = 61,
            KEY_RIGHT = 62,
            KEY_UP = 63,
            KEY_DOWN = 64,

            KEY_LEFT_SHIFT = 65,
            KEY_RIGHT_SHIFT = 66,
            KEY_LEFT_CONTROL = 67,
            KEY_RIGHT_CONTROL = 68,
            KEY_LEFT_ALT = 69,
            KEY_RIGHT_ALT = 70,
            KEY_LEFT_SUPER = 71,
            KEY_RIGHT_SUPER = 72,

            KEY_SPACE = 73,
            KEY_APOSTROPHE = 74,
            KEY_COMMA = 75,
            KEY_PERIOD = 76,
            KEY_SLASH = 77,
            KEY_SEMICOLON = 78,
            KEY_EQUAL = 79,
            KEY_LEFT_BRACKET = 80,
            KEY_BACKSLASH = 81,
            KEY_RIGHT_BRACKET = 82,
            KEY_GRAVE_ACCENT = 83,
            KEY_WORLD_1 = 84,
            KEY_WORLD_2 = 85,
            KEY_ESCAPE = 86,
            KEY_ENTER = 87,
            KEY_TAB = 88,
            KEY_BACKSPACE = 89,
            KEY_INSERT = 90,
            KEY_DELETE = 91,
            KEY_PAGE_UP = 92,
            KEY_PAGE_DOWN = 93,
            KEY_HOME = 94,
            KEY_END = 95,
            KEY_CAPS_LOCK = 96,
            KEY_SCROLL_LOCK = 97,
            KEY_NUM_LOCK = 98,
            KEY_PRINT_SCREEN = 99,
            KEY_PAUSE = 100,
            KEY_MENU = 101,

            KEY_NUMPAD_DECIMAL = 102,
            KEY_NUMPAD_DIVIDE = 103,
            KEY_NUMPAD_MULTIPLY = 104,
            KEY_NUMPAD_SUBTRACT = 105,
            KEY_NUMPAD_ADD = 106,
            KEY_NUMPAD_ENTER = 107,
            KEY_NUMPAD_EQUAL = 108,
            KEY_NUMPAD_0 = 109,
            KEY_NUMPAD_1 = 110,
            KEY_NUMPAD_2 = 111,
            KEY_NUMPAD_3 = 112,
            KEY_NUMPAD_4 = 113,
            KEY_NUMPAD_5 = 114,
            KEY_NUMPAD_6 = 115,
            KEY_NUMPAD_7 = 116,
            KEY_NUMPAD_8 = 117,
            KEY_NUMPAD_9 = 118,

            // Mouse
            MOUSE_BUTTON_1 = 119,
            MOUSE_BUTTON_2 = 120,
            MOUSE_BUTTON_3 = 121,
            MOUSE_BUTTON_4 = 122,
            MOUSE_BUTTON_5 = 123,
            MOUSE_BUTTON_6 = 124,
            MOUSE_BUTTON_7 = 125,
            MOUSE_BUTTON_8 = 126,
            MOUSE_BUTTON_LEFT = 127,
            MOUSE_BUTTON_RIGHT = 128,
            MOUSE_BUTTON_MIDDLE = 129,

            MOUSE_AXIS_SCROLL = 130,
            MOUSE_AXIS_HORIZONTAL = 131,
            MOUSE_AXIS_VERTICAL = 132,

            // Generic controller
            CONTROLLER_BUTTON_A = 133,
            CONTROLLER_BUTTON_B = 134,
            CONTROLLER_BUTTON_X = 135,
            CONTROLLER_BUTTON_Y = 136,
            CONTROLLER_BUTTON_BUMPER_LEFT = 137,
            CONTROLLER_BUTTON_BUMPER_RIGHT = 138,
            CONTROLLER_BUTTON_BACK = 139,
            CONTROLLER_BUTTON_START = 140,
            CONTROLLER_BUTTON_GUIDE = 141,
            CONTROLLER_BUTTON_THUMB_LEFT = 142,
            CONTROLLER_BUTTON_THUMB_RIGHT = 143,
            CONTROLLER_BUTTON_DPAD_UP = 144,
            CONTROLLER_BUTTON_DPAD_RIGHT = 145,
            CONTROLLER_BUTTON_DPAD_DOWN = 146,
            CONTROLLER_BUTTON_DPAD_LEFT = 147,




            CONTROLLER_AXIS_LEFT_X = 148,
            CONTROLLER_AXIS_LEFT_Y = 149,
            CONTROLLER_AXIS_LEFT_TRIGGER = 150,
            CONTROLLER_AXIS_RIGHT_X = 151,
            CONTROLLER_AXIS_RIGHT_Y = 152,
            CONTROLLER_AXIS_RIGHT_TRIGGER = 153
        };

        const InputType KEYBOARD_START = ore::input::InputType::KEY_A;
        const InputType KEYBOARD_END = ore::input::InputType::KEY_NUMPAD_9;

        const InputType MOUSE_BUTTON_START = ore::input::InputType::MOUSE_BUTTON_1;
        const InputType MOUSE_BUTTON_END = ore::input::InputType::MOUSE_BUTTON_MIDDLE;

        const InputType MOUSE_AXIS_START = ore::input::InputType::MOUSE_AXIS_SCROLL;
        const InputType MOUSE_AXIS_END = ore::input::InputType::MOUSE_AXIS_VERTICAL;

        const InputType CONTROLLER_BUTTON_START = ore::input::InputType::CONTROLLER_BUTTON_A;
        const InputType CONTROLLER_BUTTON_END = ore::input::InputType::CONTROLLER_BUTTON_DPAD_LEFT;

        const InputType CONTROLLER_AXIS_START = ore::input::InputType::CONTROLLER_AXIS_LEFT_X;
        const InputType CONTROLLER_AXIS_END = ore::input::InputType::CONTROLLER_AXIS_RIGHT_TRIGGER;

        int toGLFWEnum(ore::input::InputType type);
        ore::input::InputType fromGLFWKeyboardEnum(int type);
        ore::input::InputType fromGLFWMouseEnum(int type);
        ore::input::InputType fromGLFWGamepadButtonEnum(int type);
        ore::input::InputType fromGLFWGamepadAxisEnum(int type);

        std::string inputTypeToString(ore::input::InputType type);
        ore::input::InputType parseInputType(std::string &typeString);
    }
}