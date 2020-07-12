#include <stdexcept>
#include "InputType.h"

std::string ore::input::inputTypeToString(ore::input::InputType type) {
    switch(type) {
        case InputType::KEY_A:
            return "KEY_A";
        case InputType::KEY_B:
            return "KEY_B";
        case InputType::KEY_C:
            return "KEY_C";
        case InputType::KEY_D:
            return "KEY_D";
        case InputType::KEY_E:
            return "KEY_E";
        case InputType::KEY_F:
            return "KEY_F";
        case InputType::KEY_G:
            return "KEY_G";
        case InputType::KEY_H:
            return "KEY_H";
        case InputType::KEY_I:
            return "KEY_I";
        case InputType::KEY_J:
            return "KEY_J";
        case InputType::KEY_K:
            return "KEY_K";
        case InputType::KEY_L:
            return "KEY_L";
        case InputType::KEY_M:
            return "KEY_M";
        case InputType::KEY_N:
            return "KEY_N";
        case InputType::KEY_O:
            return "KEY_O";
        case InputType::KEY_P:
            return "KEY_P";
        case InputType::KEY_Q:
            return "KEY_Q";
        case InputType::KEY_R:
            return "KEY_R";
        case InputType::KEY_S:
            return "KEY_S";
        case InputType::KEY_T:
            return "KEY_T";
        case InputType::KEY_U:
            return "KEY_U";
        case InputType::KEY_V:
            return "KEY_V";
        case InputType::KEY_W:
            return "KEY_W";
        case InputType::KEY_X:
            return "KEY_X";
        case InputType::KEY_Y:
            return "KEY_Y";
        case InputType::KEY_Z:
            return "KEY_Z";
        case InputType::KEY_0:
            return "KEY_0";
        case InputType::KEY_1:
            return "KEY_1";
        case InputType::KEY_2:
            return "KEY_2";
        case InputType::KEY_3:
            return "KEY_3";
        case InputType::KEY_4:
            return "KEY_4";
        case InputType::KEY_5:
            return "KEY_5";
        case InputType::KEY_6:
            return "KEY_6";
        case InputType::KEY_7:
            return "KEY_7";
        case InputType::KEY_8:
            return "KEY_8";
        case InputType::KEY_9:
            return "KEY_9";
        case InputType::KEY_F1:
            return "KEY_F1";
        case InputType::KEY_F2:
            return "KEY_F2";
        case InputType::KEY_F3:
            return "KEY_F3";
        case InputType::KEY_F4:
            return "KEY_F4";
        case InputType::KEY_F5:
            return "KEY_F5";
        case InputType::KEY_F6:
            return "KEY_F6";
        case InputType::KEY_F7:
            return "KEY_F7";
        case InputType::KEY_F8:
            return "KEY_F8";
        case InputType::KEY_F9:
            return "KEY_F9";
        case InputType::KEY_F10:
            return "KEY_F10";
        case InputType::KEY_F11:
            return "KEY_F11";
        case InputType::KEY_F12:
            return "KEY_F12";
        case InputType::KEY_F13:
            return "KEY_F13";
        case InputType::KEY_F14:
            return "KEY_F14";
        case InputType::KEY_F15:
            return "KEY_F15";
        case InputType::KEY_F16:
            return "KEY_F16";
        case InputType::KEY_F17:
            return "KEY_F17";
        case InputType::KEY_F18:
            return "KEY_F18";
        case InputType::KEY_F19:
            return "KEY_F19";
        case InputType::KEY_F20:
            return "KEY_F20";
        case InputType::KEY_F21:
            return "KEY_F21";
        case InputType::KEY_F22:
            return "KEY_F22";
        case InputType::KEY_F23:
            return "KEY_F23";
        case InputType::KEY_F24:
            return "KEY_F24";
        case InputType::KEY_F25:
            return "KEY_F25";
        case InputType::KEY_LEFT:
            return "KEY_LEFT";
        case InputType::KEY_RIGHT:
            return "KEY_RIGHT";
        case InputType::KEY_UP:
            return "KEY_UP";
        case InputType::KEY_DOWN:
            return "KEY_DOWN";
        case InputType::KEY_LEFT_SHIFT:
            return "KEY_LEFT_SHIFT";
        case InputType::KEY_RIGHT_SHIFT:
            return "KEY_RIGHT_SHIFT";
        case InputType::KEY_LEFT_CONTROL:
            return "KEY_LEFT_CONTROL";
        case InputType::KEY_RIGHT_CONTROL:
            return "KEY_RIGHT_CONTROL";
        case InputType::KEY_LEFT_ALT:
            return "KEY_LEFT_ALT";
        case InputType::KEY_RIGHT_ALT:
            return "KEY_RIGHT_ALT";
        case InputType::KEY_LEFT_SUPER:
            return "KEY_LEFT_SUPER";
        case InputType::KEY_RIGHT_SUPER:
            return "KEY_RIGHT_SUPER";
        case InputType::KEY_SPACE:
            return "KEY_SPACE";
        case InputType::KEY_APOSTROPHE:
            return "KEY_APOSTROPHE";
        case InputType::KEY_COMMA:
            return "KEY_COMMA";
        case InputType::KEY_PERIOD:
            return "KEY_PERIOD";
        case InputType::KEY_SLASH:
            return "KEY_SLASH";
        case InputType::KEY_SEMICOLON:
            return "KEY_SEMICOLON";
        case InputType::KEY_EQUAL:
            return "KEY_EQUAL";
        case InputType::KEY_LEFT_BRACKET:
            return "KEY_LEFT_BRACKET";
        case InputType::KEY_BACKSLASH:
            return "KEY_BACKSLASH";
        case InputType::KEY_RIGHT_BRACKET:
            return "KEY_RIGHT_BRACKET";
        case InputType::KEY_GRAVE_ACCENT:
            return "KEY_GRAVE_ACCENT";
        case InputType::KEY_WORLD_1:
            return "KEY_WORLD_1";
        case InputType::KEY_WORLD_2:
            return "KEY_WORLD_2";
        case InputType::KEY_ESCAPE:
            return "KEY_ESCAPE";
        case InputType::KEY_ENTER:
            return "KEY_ENTER";
        case InputType::KEY_TAB:
            return "KEY_TAB";
        case InputType::KEY_BACKSPACE:
            return "KEY_BACKSPACE";
        case InputType::KEY_INSERT:
            return "KEY_INSERT";
        case InputType::KEY_DELETE:
            return "KEY_DELETE";
        case InputType::KEY_PAGE_UP:
            return "KEY_PAGE_UP";
        case InputType::KEY_PAGE_DOWN:
            return "KEY_PAGE_DOWN";
        case InputType::KEY_HOME:
            return "KEY_HOME";
        case InputType::KEY_END:
            return "KEY_END";
        case InputType::KEY_CAPS_LOCK:
            return "KEY_CAPS_LOCK";
        case InputType::KEY_SCROLL_LOCK:
            return "KEY_SCROLL_LOCK";
        case InputType::KEY_NUM_LOCK:
            return "KEY_NUM_LOCK";
        case InputType::KEY_PRINT_SCREEN:
            return "KEY_PRINT_SCREEN";
        case InputType::KEY_PAUSE:
            return "KEY_PAUSE";
        case InputType::KEY_MENU:
            return "KEY_MENU";
        case InputType::KEY_NUMPAD_DECIMAL:
            return "KEY_NUMPAD_DECIMAL";
        case InputType::KEY_NUMPAD_DIVIDE:
            return "KEY_NUMPAD_DIVIDE";
        case InputType::KEY_NUMPAD_MULTIPLY:
            return "KEY_NUMPAD_MULTIPLY";
        case InputType::KEY_NUMPAD_SUBTRACT:
            return "KEY_NUMPAD_SUBTRACT";
        case InputType::KEY_NUMPAD_ADD:
            return "KEY_NUMPAD_ADD";
        case InputType::KEY_NUMPAD_ENTER:
            return "KEY_NUMPAD_ENTER";
        case InputType::KEY_NUMPAD_EQUAL:
            return "KEY_NUMPAD_EQUAL";
        case InputType::KEY_NUMPAD_0:
            return "KEY_NUMPAD_0";
        case InputType::KEY_NUMPAD_1:
            return "KEY_NUMPAD_1";
        case InputType::KEY_NUMPAD_2:
            return "KEY_NUMPAD_2";
        case InputType::KEY_NUMPAD_3:
            return "KEY_NUMPAD_3";
        case InputType::KEY_NUMPAD_4:
            return "KEY_NUMPAD_4";
        case InputType::KEY_NUMPAD_5:
            return "KEY_NUMPAD_5";
        case InputType::KEY_NUMPAD_6:
            return "KEY_NUMPAD_6";
        case InputType::KEY_NUMPAD_7:
            return "KEY_NUMPAD_7";
        case InputType::KEY_NUMPAD_8:
            return "KEY_NUMPAD_8";
        case InputType::KEY_NUMPAD_9:
            return "KEY_NUMPAD_9";
        case InputType::MOUSE_BUTTON_1:
            return "MOUSE_BUTTON_1";
        case InputType::MOUSE_BUTTON_2:
            return "MOUSE_BUTTON_2";
        case InputType::MOUSE_BUTTON_3:
            return "MOUSE_BUTTON_3";
        case InputType::MOUSE_BUTTON_4:
            return "MOUSE_BUTTON_4";
        case InputType::MOUSE_BUTTON_5:
            return "MOUSE_BUTTON_5";
        case InputType::MOUSE_BUTTON_6:
            return "MOUSE_BUTTON_6";
        case InputType::MOUSE_BUTTON_7:
            return "MOUSE_BUTTON_7";
        case InputType::MOUSE_BUTTON_8:
            return "MOUSE_BUTTON_8";
        case InputType::MOUSE_BUTTON_LEFT:
            return "MOUSE_BUTTON_LEFT";
        case InputType::MOUSE_BUTTON_RIGHT:
            return "MOUSE_BUTTON_RIGHT";
        case InputType::MOUSE_BUTTON_MIDDLE:
            return "MOUSE_BUTTON_MIDDLE";
        case InputType::MOUSE_AXIS_SCROLL:
            return "MOUSE_AXIS_SCROLL";
        case InputType::MOUSE_AXIS_HORIZONTAL:
            return "MOUSE_AXIS_HORIZONTAL";
        case InputType::MOUSE_AXIS_VERTICAL:
            return "MOUSE_AXIS_VERTICAL";
        case InputType::CONTROLLER_BUTTON_1:
            return "CONTROLLER_BUTTON_1";
        case InputType::CONTROLLER_BUTTON_2:
            return "CONTROLLER_BUTTON_2";
        case InputType::CONTROLLER_BUTTON_3:
            return "CONTROLLER_BUTTON_3";
        case InputType::CONTROLLER_BUTTON_4:
            return "CONTROLLER_BUTTON_4";
        case InputType::CONTROLLER_BUTTON_5:
            return "CONTROLLER_BUTTON_5";
        case InputType::CONTROLLER_BUTTON_6:
            return "CONTROLLER_BUTTON_6";
        case InputType::CONTROLLER_BUTTON_7:
            return "CONTROLLER_BUTTON_7";
        case InputType::CONTROLLER_BUTTON_8:
            return "CONTROLLER_BUTTON_8";
        case InputType::CONTROLLER_BUTTON_9:
            return "CONTROLLER_BUTTON_9";
        case InputType::CONTROLLER_BUTTON_10:
            return "CONTROLLER_BUTTON_10";
        case InputType::CONTROLLER_BUTTON_11:
            return "CONTROLLER_BUTTON_11";
        case InputType::CONTROLLER_BUTTON_12:
            return "CONTROLLER_BUTTON_12";
        case InputType::CONTROLLER_BUTTON_13:
            return "CONTROLLER_BUTTON_13";
        case InputType::CONTROLLER_BUTTON_14:
            return "CONTROLLER_BUTTON_14";
        case InputType::CONTROLLER_BUTTON_15:
            return "CONTROLLER_BUTTON_15";
        case InputType::CONTROLLER_AXIS_1:
            return "CONTROLLER_AXIS_1";
        case InputType::CONTROLLER_AXIS_2:
            return "CONTROLLER_AXIS_2";
        case InputType::CONTROLLER_AXIS_3:
            return "CONTROLLER_AXIS_3";
        case InputType::CONTROLLER_AXIS_4:
            return "CONTROLLER_AXIS_4";
        case InputType::CONTROLLER_AXIS_5:
            return "CONTROLLER_AXIS_5";
        case InputType::CONTROLLER_AXIS_6:
            return "CONTROLLER_AXIS_6";
        case InputType::CONTROLLER_AXIS_7:
            return "CONTROLLER_AXIS_7";
        case InputType::CONTROLLER_AXIS_8:
            return "CONTROLLER_AXIS_8";
        case InputType::CONTROLLER_AXIS_9:
            return "CONTROLLER_AXIS_9";
        case InputType::CONTROLLER_AXIS_10:
            return "CONTROLLER_AXIS_10";
        case InputType::CONTROLLER_AXIS_11:
            return "CONTROLLER_AXIS_11";
        case InputType::CONTROLLER_AXIS_12:
            return "CONTROLLER_AXIS_12";
        case InputType::CONTROLLER_AXIS_13:
            return "CONTROLLER_AXIS_13";
        case InputType::CONTROLLER_AXIS_14:
            return "CONTROLLER_AXIS_14";
        case InputType::CONTROLLER_AXIS_15:
            return "CONTROLLER_AXIS_15";
        case InputType::XBOX_ONE_CONTROLLER_BUTTON_A:
            return "XBOX_ONE_CONTROLLER_BUTTON_A";
        case InputType::XBOX_ONE_CONTROLLER_BUTTON_B:
            return "XBOX_ONE_CONTROLLER_BUTTON_B";
        case InputType::XBOX_ONE_CONTROLLER_BUTTON_X:
            return "XBOX_ONE_CONTROLLER_BUTTON_X";
        case InputType::XBOX_ONE_CONTROLLER_BUTTON_Y:
            return "XBOX_ONE_CONTROLLER_BUTTON_Y";
        case InputType::XBOX_ONE_CONTROLLER_BUTTON_DPAD_UP:
            return "XBOX_ONE_CONTROLLER_BUTTON_DPAD_UP";
        case InputType::XBOX_ONE_CONTROLLER_BUTTON_DPAD_DOWN:
            return "XBOX_ONE_CONTROLLER_BUTTON_DPAD_DOWN";
        case InputType::XBOX_ONE_CONTROLLER_BUTTON_DPAD_LEFT:
            return "XBOX_ONE_CONTROLLER_BUTTON_DPAD_LEFT";
        case InputType::XBOX_ONE_CONTROLLER_BUTTON_DPAD_RIGHT:
            return "XBOX_ONE_CONTROLLER_BUTTON_DPAD_RIGHT";
        case InputType::XBOX_ONE_CONTROLLER_BUTTON_SELECT:
            return "XBOX_ONE_CONTROLLER_BUTTON_SELECT";
        case InputType::XBOX_ONE_CONTROLLER_BUTTON_START:
            return "XBOX_ONE_CONTROLLER_BUTTON_START";
        case InputType::XBOX_ONE_CONTROLLER_BUTTON_SHOULDER_LEFT:
            return "XBOX_ONE_CONTROLLER_BUTTON_SHOULDER_LEFT";
        case InputType::XBOX_ONE_CONTROLLER_BUTTON_SHOULDER_RIGHT:
            return "XBOX_ONE_CONTROLLER_BUTTON_SHOULDER_RIGHT";
        case InputType::XBOX_ONE_CONTROLLER_BUTTON_STICK_LEFT:
            return "XBOX_ONE_CONTROLLER_BUTTON_STICK_LEFT";
        case InputType::XBOX_ONE_CONTROLLER_BUTTON_STICK_RIGHT:
            return "XBOX_ONE_CONTROLLER_BUTTON_STICK_RIGHT";
        case InputType::XBOX_ONE_CONTROLLER_AXIS_STICK_LEFT_HORIZONTAL:
            return "XBOX_ONE_CONTROLLER_AXIS_STICK_LEFT_HORIZONTAL";
        case InputType::XBOX_ONE_CONTROLLER_AXIS_STICK_LEFT_VERTICAL:
            return "XBOX_ONE_CONTROLLER_AXIS_STICK_LEFT_VERTICAL";
        case InputType::XBOX_ONE_CONTROLLER_AXIS_STICK_RIGHT_HORIZONTAL:
            return "XBOX_ONE_CONTROLLER_AXIS_STICK_RIGHT_HORIZONTAL";
        case InputType::XBOX_ONE_CONTROLLER_AXIS_STICK_RIGHT_VERTICAL:
            return "XBOX_ONE_CONTROLLER_AXIS_STICK_RIGHT_VERTICAL";
        case InputType::XBOX_ONE_CONTROLLER_AXIS_TRIGGER_LEFT:
            return "XBOX_ONE_CONTROLLER_AXIS_TRIGGER_LEFT";
        case InputType::XBOX_ONE_CONTROLLER_AXIS_TRIGGER_RIGHT:
            return "XBOX_ONE_CONTROLLER_AXIS_TRIGGER_RIGHT";
    }
}

ore::input::InputType ore::input::parseInputType(std::string &typeString) {
    if(typeString == "KEY_A") {
        return ore::input::InputType::KEY_A;
    } else if(typeString == "KEY_B") {
        return ore::input::InputType::KEY_B;
    } else if(typeString == "KEY_C") {
        return ore::input::InputType::KEY_C;
    } else if(typeString == "KEY_D") {
        return ore::input::InputType::KEY_D;
    } else if(typeString == "KEY_E") {
        return ore::input::InputType::KEY_E;
    } else if(typeString == "KEY_F") {
        return ore::input::InputType::KEY_F;
    } else if(typeString == "KEY_G") {
        return ore::input::InputType::KEY_G;
    } else if(typeString == "KEY_H") {
        return ore::input::InputType::KEY_H;
    } else if(typeString == "KEY_I") {
        return ore::input::InputType::KEY_I;
    } else if(typeString == "KEY_J") {
        return ore::input::InputType::KEY_J;
    } else if(typeString == "KEY_K") {
        return ore::input::InputType::KEY_K;
    } else if(typeString == "KEY_L") {
        return ore::input::InputType::KEY_L;
    } else if(typeString == "KEY_M") {
        return ore::input::InputType::KEY_M;
    } else if(typeString == "KEY_N") {
        return ore::input::InputType::KEY_N;
    } else if(typeString == "KEY_O") {
        return ore::input::InputType::KEY_O;
    } else if(typeString == "KEY_P") {
        return ore::input::InputType::KEY_P;
    } else if(typeString == "KEY_Q") {
        return ore::input::InputType::KEY_Q;
    } else if(typeString == "KEY_R") {
        return ore::input::InputType::KEY_R;
    } else if(typeString == "KEY_S") {
        return ore::input::InputType::KEY_S;
    } else if(typeString == "KEY_T") {
        return ore::input::InputType::KEY_T;
    } else if(typeString == "KEY_U") {
        return ore::input::InputType::KEY_U;
    } else if(typeString == "KEY_V") {
        return ore::input::InputType::KEY_V;
    } else if(typeString == "KEY_W") {
        return ore::input::InputType::KEY_W;
    } else if(typeString == "KEY_X") {
        return ore::input::InputType::KEY_X;
    } else if(typeString == "KEY_Y") {
        return ore::input::InputType::KEY_Y;
    } else if(typeString == "KEY_Z") {
        return ore::input::InputType::KEY_Z;
    } else if(typeString == "KEY_0") {
        return ore::input::InputType::KEY_0;
    } else if(typeString == "KEY_1") {
        return ore::input::InputType::KEY_1;
    } else if(typeString == "KEY_2") {
        return ore::input::InputType::KEY_2;
    } else if(typeString == "KEY_3") {
        return ore::input::InputType::KEY_3;
    } else if(typeString == "KEY_4") {
        return ore::input::InputType::KEY_4;
    } else if(typeString == "KEY_5") {
        return ore::input::InputType::KEY_5;
    } else if(typeString == "KEY_6") {
        return ore::input::InputType::KEY_6;
    } else if(typeString == "KEY_7") {
        return ore::input::InputType::KEY_7;
    } else if(typeString == "KEY_8") {
        return ore::input::InputType::KEY_8;
    } else if(typeString == "KEY_9") {
        return ore::input::InputType::KEY_9;
    } else if(typeString == "KEY_F1") {
        return ore::input::InputType::KEY_F1;
    } else if(typeString == "KEY_F2") {
        return ore::input::InputType::KEY_F2;
    } else if(typeString == "KEY_F3") {
        return ore::input::InputType::KEY_F3;
    } else if(typeString == "KEY_F4") {
        return ore::input::InputType::KEY_F4;
    } else if(typeString == "KEY_F5") {
        return ore::input::InputType::KEY_F5;
    } else if(typeString == "KEY_F6") {
        return ore::input::InputType::KEY_F6;
    } else if(typeString == "KEY_F7") {
        return ore::input::InputType::KEY_F7;
    } else if(typeString == "KEY_F8") {
        return ore::input::InputType::KEY_F8;
    } else if(typeString == "KEY_F9") {
        return ore::input::InputType::KEY_F9;
    } else if(typeString == "KEY_F10") {
        return ore::input::InputType::KEY_F10;
    } else if(typeString == "KEY_F11") {
        return ore::input::InputType::KEY_F11;
    } else if(typeString == "KEY_F12") {
        return ore::input::InputType::KEY_F12;
    } else if(typeString == "KEY_F13") {
        return ore::input::InputType::KEY_F13;
    } else if(typeString == "KEY_F14") {
        return ore::input::InputType::KEY_F14;
    } else if(typeString == "KEY_F15") {
        return ore::input::InputType::KEY_F15;
    } else if(typeString == "KEY_F16") {
        return ore::input::InputType::KEY_F16;
    } else if(typeString == "KEY_F17") {
        return ore::input::InputType::KEY_F17;
    } else if(typeString == "KEY_F18") {
        return ore::input::InputType::KEY_F18;
    } else if(typeString == "KEY_F19") {
        return ore::input::InputType::KEY_F19;
    } else if(typeString == "KEY_F20") {
        return ore::input::InputType::KEY_F20;
    } else if(typeString == "KEY_F21") {
        return ore::input::InputType::KEY_F21;
    } else if(typeString == "KEY_F22") {
        return ore::input::InputType::KEY_F22;
    } else if(typeString == "KEY_F23") {
        return ore::input::InputType::KEY_F23;
    } else if(typeString == "KEY_F24") {
        return ore::input::InputType::KEY_F24;
    } else if(typeString == "KEY_F25") {
        return ore::input::InputType::KEY_F25;
    } else if(typeString == "KEY_LEFT") {
        return ore::input::InputType::KEY_LEFT;
    } else if(typeString == "KEY_RIGHT") {
        return ore::input::InputType::KEY_RIGHT;
    } else if(typeString == "KEY_UP") {
        return ore::input::InputType::KEY_UP;
    } else if(typeString == "KEY_DOWN") {
        return ore::input::InputType::KEY_DOWN;
    } else if(typeString == "KEY_LEFT_SHIFT") {
        return ore::input::InputType::KEY_LEFT_SHIFT;
    } else if(typeString == "KEY_RIGHT_SHIFT") {
        return ore::input::InputType::KEY_RIGHT_SHIFT;
    } else if(typeString == "KEY_LEFT_CONTROL") {
        return ore::input::InputType::KEY_LEFT_CONTROL;
    } else if(typeString == "KEY_RIGHT_CONTROL") {
        return ore::input::InputType::KEY_RIGHT_CONTROL;
    } else if(typeString == "KEY_LEFT_ALT") {
        return ore::input::InputType::KEY_LEFT_ALT;
    } else if(typeString == "KEY_RIGHT_ALT") {
        return ore::input::InputType::KEY_RIGHT_ALT;
    } else if(typeString == "KEY_LEFT_SUPER") {
        return ore::input::InputType::KEY_LEFT_SUPER;
    } else if(typeString == "KEY_RIGHT_SUPER") {
        return ore::input::InputType::KEY_RIGHT_SUPER;
    } else if(typeString == "KEY_SPACE") {
        return ore::input::InputType::KEY_SPACE;
    } else if(typeString == "KEY_APOSTROPHE") {
        return ore::input::InputType::KEY_APOSTROPHE;
    } else if(typeString == "KEY_COMMA") {
        return ore::input::InputType::KEY_COMMA;
    } else if(typeString == "KEY_PERIOD") {
        return ore::input::InputType::KEY_PERIOD;
    } else if(typeString == "KEY_SLASH") {
        return ore::input::InputType::KEY_SLASH;
    } else if(typeString == "KEY_SEMICOLON") {
        return ore::input::InputType::KEY_SEMICOLON;
    } else if(typeString == "KEY_EQUAL") {
        return ore::input::InputType::KEY_EQUAL;
    } else if(typeString == "KEY_LEFT_BRACKET") {
        return ore::input::InputType::KEY_LEFT_BRACKET;
    } else if(typeString == "KEY_BACKSLASH") {
        return ore::input::InputType::KEY_BACKSLASH;
    } else if(typeString == "KEY_RIGHT_BRACKET") {
        return ore::input::InputType::KEY_RIGHT_BRACKET;
    } else if(typeString == "KEY_GRAVE_ACCENT") {
        return ore::input::InputType::KEY_GRAVE_ACCENT;
    } else if(typeString == "KEY_WORLD_1") {
        return ore::input::InputType::KEY_WORLD_1;
    } else if(typeString == "KEY_WORLD_2") {
        return ore::input::InputType::KEY_WORLD_2;
    } else if(typeString == "KEY_ESCAPE") {
        return ore::input::InputType::KEY_ESCAPE;
    } else if(typeString == "KEY_ENTER") {
        return ore::input::InputType::KEY_ENTER;
    } else if(typeString == "KEY_TAB") {
        return ore::input::InputType::KEY_TAB;
    } else if(typeString == "KEY_BACKSPACE") {
        return ore::input::InputType::KEY_BACKSPACE;
    } else if(typeString == "KEY_INSERT") {
        return ore::input::InputType::KEY_INSERT;
    } else if(typeString == "KEY_DELETE") {
        return ore::input::InputType::KEY_DELETE;
    } else if(typeString == "KEY_PAGE_UP") {
        return ore::input::InputType::KEY_PAGE_UP;
    } else if(typeString == "KEY_PAGE_DOWN") {
        return ore::input::InputType::KEY_PAGE_DOWN;
    } else if(typeString == "KEY_HOME") {
        return ore::input::InputType::KEY_HOME;
    } else if(typeString == "KEY_END") {
        return ore::input::InputType::KEY_END;
    } else if(typeString == "KEY_CAPS_LOCK") {
        return ore::input::InputType::KEY_CAPS_LOCK;
    } else if(typeString == "KEY_SCROLL_LOCK") {
        return ore::input::InputType::KEY_SCROLL_LOCK;
    } else if(typeString == "KEY_NUM_LOCK") {
        return ore::input::InputType::KEY_NUM_LOCK;
    } else if(typeString == "KEY_PRINT_SCREEN") {
        return ore::input::InputType::KEY_PRINT_SCREEN;
    } else if(typeString == "KEY_PAUSE") {
        return ore::input::InputType::KEY_PAUSE;
    } else if(typeString == "KEY_MENU") {
        return ore::input::InputType::KEY_MENU;
    } else if(typeString == "KEY_NUMPAD_DECIMAL") {
        return ore::input::InputType::KEY_NUMPAD_DECIMAL;
    } else if(typeString == "KEY_NUMPAD_DIVIDE") {
        return ore::input::InputType::KEY_NUMPAD_DIVIDE;
    } else if(typeString == "KEY_NUMPAD_MULTIPLY") {
        return ore::input::InputType::KEY_NUMPAD_MULTIPLY;
    } else if(typeString == "KEY_NUMPAD_SUBTRACT") {
        return ore::input::InputType::KEY_NUMPAD_SUBTRACT;
    } else if(typeString == "KEY_NUMPAD_ADD") {
        return ore::input::InputType::KEY_NUMPAD_ADD;
    } else if(typeString == "KEY_NUMPAD_ENTER") {
        return ore::input::InputType::KEY_NUMPAD_ENTER;
    } else if(typeString == "KEY_NUMPAD_EQUAL") {
        return ore::input::InputType::KEY_NUMPAD_EQUAL;
    } else if(typeString == "KEY_NUMPAD_0") {
        return ore::input::InputType::KEY_NUMPAD_0;
    } else if(typeString == "KEY_NUMPAD_1") {
        return ore::input::InputType::KEY_NUMPAD_1;
    } else if(typeString == "KEY_NUMPAD_2") {
        return ore::input::InputType::KEY_NUMPAD_2;
    } else if(typeString == "KEY_NUMPAD_3") {
        return ore::input::InputType::KEY_NUMPAD_3;
    } else if(typeString == "KEY_NUMPAD_4") {
        return ore::input::InputType::KEY_NUMPAD_4;
    } else if(typeString == "KEY_NUMPAD_5") {
        return ore::input::InputType::KEY_NUMPAD_5;
    } else if(typeString == "KEY_NUMPAD_6") {
        return ore::input::InputType::KEY_NUMPAD_6;
    } else if(typeString == "KEY_NUMPAD_7") {
        return ore::input::InputType::KEY_NUMPAD_7;
    } else if(typeString == "KEY_NUMPAD_8") {
        return ore::input::InputType::KEY_NUMPAD_8;
    } else if(typeString == "KEY_NUMPAD_9") {
        return ore::input::InputType::KEY_NUMPAD_9;
    } else if(typeString == "MOUSE_BUTTON_1") {
        return ore::input::InputType::MOUSE_BUTTON_1;
    } else if(typeString == "MOUSE_BUTTON_2") {
        return ore::input::InputType::MOUSE_BUTTON_2;
    } else if(typeString == "MOUSE_BUTTON_3") {
        return ore::input::InputType::MOUSE_BUTTON_3;
    } else if(typeString == "MOUSE_BUTTON_4") {
        return ore::input::InputType::MOUSE_BUTTON_4;
    } else if(typeString == "MOUSE_BUTTON_5") {
        return ore::input::InputType::MOUSE_BUTTON_5;
    } else if(typeString == "MOUSE_BUTTON_6") {
        return ore::input::InputType::MOUSE_BUTTON_6;
    } else if(typeString == "MOUSE_BUTTON_7") {
        return ore::input::InputType::MOUSE_BUTTON_7;
    } else if(typeString == "MOUSE_BUTTON_8") {
        return ore::input::InputType::MOUSE_BUTTON_8;
    } else if(typeString == "MOUSE_BUTTON_LEFT") {
        return ore::input::InputType::MOUSE_BUTTON_LEFT;
    } else if(typeString == "MOUSE_BUTTON_RIGHT") {
        return ore::input::InputType::MOUSE_BUTTON_RIGHT;
    } else if(typeString == "MOUSE_BUTTON_MIDDLE") {
        return ore::input::InputType::MOUSE_BUTTON_MIDDLE;
    } else if(typeString == "MOUSE_AXIS_SCROLL") {
        return ore::input::InputType::MOUSE_AXIS_SCROLL;
    } else if(typeString == "MOUSE_AXIS_HORIZONTAL") {
        return ore::input::InputType::MOUSE_AXIS_HORIZONTAL;
    } else if(typeString == "MOUSE_AXIS_VERTICAL") {
        return ore::input::InputType::MOUSE_AXIS_VERTICAL;
    } else if(typeString == "CONTROLLER_BUTTON_1") {
        return ore::input::InputType::CONTROLLER_BUTTON_1;
    } else if(typeString == "CONTROLLER_BUTTON_2") {
        return ore::input::InputType::CONTROLLER_BUTTON_2;
    } else if(typeString == "CONTROLLER_BUTTON_3") {
        return ore::input::InputType::CONTROLLER_BUTTON_3;
    } else if(typeString == "CONTROLLER_BUTTON_4") {
        return ore::input::InputType::CONTROLLER_BUTTON_4;
    } else if(typeString == "CONTROLLER_BUTTON_5") {
        return ore::input::InputType::CONTROLLER_BUTTON_5;
    } else if(typeString == "CONTROLLER_BUTTON_6") {
        return ore::input::InputType::CONTROLLER_BUTTON_6;
    } else if(typeString == "CONTROLLER_BUTTON_7") {
        return ore::input::InputType::CONTROLLER_BUTTON_7;
    } else if(typeString == "CONTROLLER_BUTTON_8") {
        return ore::input::InputType::CONTROLLER_BUTTON_8;
    } else if(typeString == "CONTROLLER_BUTTON_9") {
        return ore::input::InputType::CONTROLLER_BUTTON_9;
    } else if(typeString == "CONTROLLER_BUTTON_10") {
        return ore::input::InputType::CONTROLLER_BUTTON_10;
    } else if(typeString == "CONTROLLER_BUTTON_11") {
        return ore::input::InputType::CONTROLLER_BUTTON_11;
    } else if(typeString == "CONTROLLER_BUTTON_12") {
        return ore::input::InputType::CONTROLLER_BUTTON_12;
    } else if(typeString == "CONTROLLER_BUTTON_13") {
        return ore::input::InputType::CONTROLLER_BUTTON_13;
    } else if(typeString == "CONTROLLER_BUTTON_14") {
        return ore::input::InputType::CONTROLLER_BUTTON_14;
    } else if(typeString == "CONTROLLER_BUTTON_15") {
        return ore::input::InputType::CONTROLLER_BUTTON_15;
    } else if(typeString == "CONTROLLER_AXIS_1") {
        return ore::input::InputType::CONTROLLER_AXIS_1;
    } else if(typeString == "CONTROLLER_AXIS_2") {
        return ore::input::InputType::CONTROLLER_AXIS_2;
    } else if(typeString == "CONTROLLER_AXIS_3") {
        return ore::input::InputType::CONTROLLER_AXIS_3;
    } else if(typeString == "CONTROLLER_AXIS_4") {
        return ore::input::InputType::CONTROLLER_AXIS_4;
    } else if(typeString == "CONTROLLER_AXIS_5") {
        return ore::input::InputType::CONTROLLER_AXIS_5;
    } else if(typeString == "CONTROLLER_AXIS_6") {
        return ore::input::InputType::CONTROLLER_AXIS_6;
    } else if(typeString == "CONTROLLER_AXIS_7") {
        return ore::input::InputType::CONTROLLER_AXIS_7;
    } else if(typeString == "CONTROLLER_AXIS_8") {
        return ore::input::InputType::CONTROLLER_AXIS_8;
    } else if(typeString == "CONTROLLER_AXIS_9") {
        return ore::input::InputType::CONTROLLER_AXIS_9;
    } else if(typeString == "CONTROLLER_AXIS_10") {
        return ore::input::InputType::CONTROLLER_AXIS_10;
    } else if(typeString == "CONTROLLER_AXIS_11") {
        return ore::input::InputType::CONTROLLER_AXIS_11;
    } else if(typeString == "CONTROLLER_AXIS_12") {
        return ore::input::InputType::CONTROLLER_AXIS_12;
    } else if(typeString == "CONTROLLER_AXIS_13") {
        return ore::input::InputType::CONTROLLER_AXIS_13;
    } else if(typeString == "CONTROLLER_AXIS_14") {
        return ore::input::InputType::CONTROLLER_AXIS_14;
    } else if(typeString == "CONTROLLER_AXIS_15") {
        return ore::input::InputType::CONTROLLER_AXIS_15;
    } else if(typeString == "XBOX_ONE_CONTROLLER_BUTTON_A") {
        return ore::input::InputType::XBOX_ONE_CONTROLLER_BUTTON_A;
    } else if(typeString == "XBOX_ONE_CONTROLLER_BUTTON_B") {
        return ore::input::InputType::XBOX_ONE_CONTROLLER_BUTTON_B;
    } else if(typeString == "XBOX_ONE_CONTROLLER_BUTTON_X") {
        return ore::input::InputType::XBOX_ONE_CONTROLLER_BUTTON_X;
    } else if(typeString == "XBOX_ONE_CONTROLLER_BUTTON_Y") {
        return ore::input::InputType::XBOX_ONE_CONTROLLER_BUTTON_Y;
    } else if(typeString == "XBOX_ONE_CONTROLLER_BUTTON_DPAD_UP") {
        return ore::input::InputType::XBOX_ONE_CONTROLLER_BUTTON_DPAD_UP;
    } else if(typeString == "XBOX_ONE_CONTROLLER_BUTTON_DPAD_DOWN") {
        return ore::input::InputType::XBOX_ONE_CONTROLLER_BUTTON_DPAD_DOWN;
    } else if(typeString == "XBOX_ONE_CONTROLLER_BUTTON_DPAD_LEFT") {
        return ore::input::InputType::XBOX_ONE_CONTROLLER_BUTTON_DPAD_LEFT;
    } else if(typeString == "XBOX_ONE_CONTROLLER_BUTTON_DPAD_RIGHT") {
        return ore::input::InputType::XBOX_ONE_CONTROLLER_BUTTON_DPAD_RIGHT;
    } else if(typeString == "XBOX_ONE_CONTROLLER_BUTTON_SELECT") {
        return ore::input::InputType::XBOX_ONE_CONTROLLER_BUTTON_SELECT;
    } else if(typeString == "XBOX_ONE_CONTROLLER_BUTTON_START") {
        return ore::input::InputType::XBOX_ONE_CONTROLLER_BUTTON_START;
    } else if(typeString == "XBOX_ONE_CONTROLLER_BUTTON_SHOULDER_LEFT") {
        return ore::input::InputType::XBOX_ONE_CONTROLLER_BUTTON_SHOULDER_LEFT;
    } else if(typeString == "XBOX_ONE_CONTROLLER_BUTTON_SHOULDER_RIGHT") {
        return ore::input::InputType::XBOX_ONE_CONTROLLER_BUTTON_SHOULDER_RIGHT;
    } else if(typeString == "XBOX_ONE_CONTROLLER_BUTTON_STICK_LEFT") {
        return ore::input::InputType::XBOX_ONE_CONTROLLER_BUTTON_STICK_LEFT;
    } else if(typeString == "XBOX_ONE_CONTROLLER_BUTTON_STICK_RIGHT") {
        return ore::input::InputType::XBOX_ONE_CONTROLLER_BUTTON_STICK_RIGHT;
    } else if(typeString == "XBOX_ONE_CONTROLLER_AXIS_STICK_LEFT_HORIZONTAL") {
        return ore::input::InputType::XBOX_ONE_CONTROLLER_AXIS_STICK_LEFT_HORIZONTAL;
    } else if(typeString == "XBOX_ONE_CONTROLLER_AXIS_STICK_LEFT_VERTICAL") {
        return ore::input::InputType::XBOX_ONE_CONTROLLER_AXIS_STICK_LEFT_VERTICAL;
    } else if(typeString == "XBOX_ONE_CONTROLLER_AXIS_STICK_RIGHT_HORIZONTAL") {
        return ore::input::InputType::XBOX_ONE_CONTROLLER_AXIS_STICK_RIGHT_HORIZONTAL;
    } else if(typeString == "XBOX_ONE_CONTROLLER_AXIS_STICK_RIGHT_VERTICAL") {
        return ore::input::InputType::XBOX_ONE_CONTROLLER_AXIS_STICK_RIGHT_VERTICAL;
    } else if(typeString == "XBOX_ONE_CONTROLLER_AXIS_TRIGGER_LEFT") {
        return ore::input::InputType::XBOX_ONE_CONTROLLER_AXIS_TRIGGER_LEFT;
    } else if(typeString == "XBOX_ONE_CONTROLLER_AXIS_TRIGGER_RIGHT") {
        return ore::input::InputType::XBOX_ONE_CONTROLLER_AXIS_TRIGGER_RIGHT;
    } else {
        throw std::runtime_error("Unrecognised input type: " + typeString);
    }
}