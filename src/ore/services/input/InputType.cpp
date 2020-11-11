#include <stdexcept>
#include <GLFW/glfw3.h>
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
        case InputType::CONTROLLER_BUTTON_A:
            return "CONTROLLER_BUTTON_A";
        case InputType::CONTROLLER_BUTTON_B:
            return "CONTROLLER_BUTTON_B";
        case InputType::CONTROLLER_BUTTON_X:
            return "CONTROLLER_BUTTON_X";
        case InputType::CONTROLLER_BUTTON_Y:
            return "CONTROLLER_BUTTON_Y";
        case InputType::CONTROLLER_BUTTON_DPAD_LEFT:
            return "CONTROLLER_BUTTON_DPAD_LEFT";
        case InputType::CONTROLLER_BUTTON_DPAD_RIGHT:
            return "CONTROLLER_BUTTON_DPAD_RIGHT";
        case InputType::CONTROLLER_BUTTON_DPAD_UP:
            return "CONTROLLER_BUTTON_DPAD_UP";
        case InputType::CONTROLLER_BUTTON_DPAD_DOWN:
            return "CONTROLLER_BUTTON_DPAD_DOWN";
        case InputType::CONTROLLER_BUTTON_BUMPER_LEFT:
            return "CONTROLLER_BUTTON_BUMPER_LEFT";
        case InputType::CONTROLLER_BUTTON_BUMPER_RIGHT:
            return "CONTROLLER_BUTTON_BUMPER_RIGHT";
        case InputType::CONTROLLER_BUTTON_BACK:
            return "CONTROLLER_BUTTON_BACK";
        case InputType::CONTROLLER_BUTTON_START:
            return "CONTROLLER_BUTTON_START";
        case InputType::CONTROLLER_BUTTON_THUMB_LEFT:
            return "CONTROLLER_BUTTON_THUMB_LEFT";
        case InputType::CONTROLLER_BUTTON_THUMB_RIGHT:
            return "CONTROLLER_BUTTON_THUMB_RIGHT";
        case InputType::CONTROLLER_BUTTON_GUIDE:
            return "CONTROLLER_BUTTON_GUIDE";
        case InputType::CONTROLLER_AXIS_LEFT_X:
            return "CONTROLLER_AXIS_LEFT_X";
        case InputType::CONTROLLER_AXIS_LEFT_Y:
            return "CONTROLLER_AXIS_LEFT_Y";
        case InputType::CONTROLLER_AXIS_RIGHT_X:
            return "CONTROLLER_AXIS_RIGHT_X";
        case InputType::CONTROLLER_AXIS_RIGHT_Y:
            return "CONTROLLER_AXIS_RIGHT_Y";
        case InputType::CONTROLLER_AXIS_LEFT_TRIGGER:
            return "CONTROLLER_AXIS_LEFT_TRIGGER";
        case InputType::CONTROLLER_AXIS_RIGHT_TRIGGER:
            return "CONTROLLER_AXIS_RIGHT_TRIGGER";
    }
    throw std::runtime_error("Unrecognised input type");
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
	} else if (typeString == "CONTROLLER_BUTTON_A") {
		return ore::input::InputType::CONTROLLER_BUTTON_A;
    } else if (typeString == "CONTROLLER_BUTTON_B") {
    	return ore::input::InputType::CONTROLLER_BUTTON_B;
    } else if (typeString == "CONTROLLER_BUTTON_X") {
    	return ore::input::InputType::CONTROLLER_BUTTON_X;
    } else if (typeString == "CONTROLLER_BUTTON_Y") {
    	return ore::input::InputType::CONTROLLER_BUTTON_Y;
    } else if (typeString == "CONTROLLER_BUTTON_DPAD_LEFT") {
    	return ore::input::InputType::CONTROLLER_BUTTON_DPAD_LEFT;
    } else if (typeString == "CONTROLLER_BUTTON_DPAD_RIGHT") {
    	return ore::input::InputType::CONTROLLER_BUTTON_DPAD_RIGHT;
    } else if (typeString == "CONTROLLER_BUTTON_DPAD_UP") {
    	return ore::input::InputType::CONTROLLER_BUTTON_DPAD_UP;
    } else if (typeString == "CONTROLLER_BUTTON_DPAD_DOWN") {
    	return ore::input::InputType::CONTROLLER_BUTTON_DPAD_DOWN;
    } else if (typeString == "CONTROLLER_BUTTON_BUMPER_LEFT") {
    	return ore::input::InputType::CONTROLLER_BUTTON_BUMPER_LEFT;
    } else if (typeString == "CONTROLLER_BUTTON_BUMPER_RIGHT") {
    	return ore::input::InputType::CONTROLLER_BUTTON_BUMPER_RIGHT;
    } else if (typeString == "CONTROLLER_BUTTON_BACK") {
    	return ore::input::InputType::CONTROLLER_BUTTON_BACK;
    } else if (typeString == "CONTROLLER_BUTTON_START") {
    	return ore::input::InputType::CONTROLLER_BUTTON_START;
    } else if (typeString == "CONTROLLER_BUTTON_THUMB_LEFT") {
    	return ore::input::InputType::CONTROLLER_BUTTON_THUMB_LEFT;
    } else if (typeString == "CONTROLLER_BUTTON_THUMB_RIGHT") {
    	return ore::input::InputType::CONTROLLER_BUTTON_THUMB_RIGHT;
    } else if (typeString == "CONTROLLER_BUTTON_GUIDE") {
    	return ore::input::InputType::CONTROLLER_BUTTON_GUIDE;
    } else if (typeString == "CONTROLLER_AXIS_LEFT_X") {
    	return ore::input::InputType::CONTROLLER_AXIS_LEFT_X;
    } else if (typeString == "CONTROLLER_AXIS_LEFT_Y") {
    	return ore::input::InputType::CONTROLLER_AXIS_LEFT_Y;
    } else if (typeString == "CONTROLLER_AXIS_RIGHT_X") {
    	return ore::input::InputType::CONTROLLER_AXIS_RIGHT_X;
    } else if (typeString == "CONTROLLER_AXIS_RIGHT_Y") {
    	return ore::input::InputType::CONTROLLER_AXIS_RIGHT_Y;
    } else if (typeString == "CONTROLLER_AXIS_LEFT_TRIGGER") {
    	return ore::input::InputType::CONTROLLER_AXIS_LEFT_TRIGGER;
    } else if (typeString == "CONTROLLER_AXIS_RIGHT_TRIGGER") {
    	return ore::input::InputType::CONTROLLER_AXIS_RIGHT_TRIGGER;
    } else {
        throw std::runtime_error("Unrecognised input type: " + typeString);
    }
}

int ore::input::toGLFWEnum(ore::input::InputType type) {
    switch(type) {
        case InputType::KEY_A:
            return GLFW_KEY_A;
        case InputType::KEY_B:
            return GLFW_KEY_B;
        case InputType::KEY_C:
            return GLFW_KEY_C;
        case InputType::KEY_D:
            return GLFW_KEY_D;
        case InputType::KEY_E:
            return GLFW_KEY_E;
        case InputType::KEY_F:
            return GLFW_KEY_F;
        case InputType::KEY_G:
            return GLFW_KEY_G;
        case InputType::KEY_H:
            return GLFW_KEY_H;
        case InputType::KEY_I:
            return GLFW_KEY_I;
        case InputType::KEY_J:
            return GLFW_KEY_J;
        case InputType::KEY_K:
            return GLFW_KEY_K;
        case InputType::KEY_L:
            return GLFW_KEY_L;
        case InputType::KEY_M:
            return GLFW_KEY_M;
        case InputType::KEY_N:
            return GLFW_KEY_N;
        case InputType::KEY_O:
            return GLFW_KEY_O;
        case InputType::KEY_P:
            return GLFW_KEY_P;
        case InputType::KEY_Q:
            return GLFW_KEY_Q;
        case InputType::KEY_R:
            return GLFW_KEY_R;
        case InputType::KEY_S:
            return GLFW_KEY_S;
        case InputType::KEY_T:
            return GLFW_KEY_T;
        case InputType::KEY_U:
            return GLFW_KEY_U;
        case InputType::KEY_V:
            return GLFW_KEY_V;
        case InputType::KEY_W:
            return GLFW_KEY_W;
        case InputType::KEY_X:
            return GLFW_KEY_X;
        case InputType::KEY_Y:
            return GLFW_KEY_Y;
        case InputType::KEY_Z:
            return GLFW_KEY_Z;
        case InputType::KEY_0:
            return GLFW_KEY_0;
        case InputType::KEY_1:
            return GLFW_KEY_1;
        case InputType::KEY_2:
            return GLFW_KEY_2;
        case InputType::KEY_3:
            return GLFW_KEY_3;
        case InputType::KEY_4:
            return GLFW_KEY_4;
        case InputType::KEY_5:
            return GLFW_KEY_5;
        case InputType::KEY_6:
            return GLFW_KEY_6;
        case InputType::KEY_7:
            return GLFW_KEY_7;
        case InputType::KEY_8:
            return GLFW_KEY_8;
        case InputType::KEY_9:
            return GLFW_KEY_9;
        case InputType::KEY_F1:
            return GLFW_KEY_F1;
        case InputType::KEY_F2:
            return GLFW_KEY_F2;
        case InputType::KEY_F3:
            return GLFW_KEY_F3;
        case InputType::KEY_F4:
            return GLFW_KEY_F4;
        case InputType::KEY_F5:
            return GLFW_KEY_F5;
        case InputType::KEY_F6:
            return GLFW_KEY_F6;
        case InputType::KEY_F7:
            return GLFW_KEY_F7;
        case InputType::KEY_F8:
            return GLFW_KEY_F8;
        case InputType::KEY_F9:
            return GLFW_KEY_F9;
        case InputType::KEY_F10:
            return GLFW_KEY_F10;
        case InputType::KEY_F11:
            return GLFW_KEY_F11;
        case InputType::KEY_F12:
            return GLFW_KEY_F12;
        case InputType::KEY_F13:
            return GLFW_KEY_F13;
        case InputType::KEY_F14:
            return GLFW_KEY_F14;
        case InputType::KEY_F15:
            return GLFW_KEY_F15;
        case InputType::KEY_F16:
            return GLFW_KEY_F16;
        case InputType::KEY_F17:
            return GLFW_KEY_F17;
        case InputType::KEY_F18:
            return GLFW_KEY_F18;
        case InputType::KEY_F19:
            return GLFW_KEY_F19;
        case InputType::KEY_F20:
            return GLFW_KEY_F20;
        case InputType::KEY_F21:
            return GLFW_KEY_F21;
        case InputType::KEY_F22:
            return GLFW_KEY_F22;
        case InputType::KEY_F23:
            return GLFW_KEY_F23;
        case InputType::KEY_F24:
            return GLFW_KEY_F24;
        case InputType::KEY_F25:
            return GLFW_KEY_F25;
        case InputType::KEY_LEFT:
            return GLFW_KEY_LEFT;
        case InputType::KEY_RIGHT:
            return GLFW_KEY_RIGHT;
        case InputType::KEY_UP:
            return GLFW_KEY_UP;
        case InputType::KEY_DOWN:
            return GLFW_KEY_DOWN;
        case InputType::KEY_LEFT_SHIFT:
            return GLFW_KEY_LEFT_SHIFT;
        case InputType::KEY_RIGHT_SHIFT:
            return GLFW_KEY_RIGHT_SHIFT;
        case InputType::KEY_LEFT_CONTROL:
            return GLFW_KEY_LEFT_CONTROL;
        case InputType::KEY_RIGHT_CONTROL:
            return GLFW_KEY_RIGHT_CONTROL;
        case InputType::KEY_LEFT_ALT:
            return GLFW_KEY_LEFT_ALT;
        case InputType::KEY_RIGHT_ALT:
            return GLFW_KEY_RIGHT_ALT;
        case InputType::KEY_LEFT_SUPER:
            return GLFW_KEY_LEFT_SUPER;
        case InputType::KEY_RIGHT_SUPER:
            return GLFW_KEY_RIGHT_SUPER;
        case InputType::KEY_SPACE:
            return GLFW_KEY_SPACE;
        case InputType::KEY_APOSTROPHE:
            return GLFW_KEY_APOSTROPHE;
        case InputType::KEY_COMMA:
            return GLFW_KEY_COMMA;
        case InputType::KEY_PERIOD:
            return GLFW_KEY_PERIOD;
        case InputType::KEY_SLASH:
            return GLFW_KEY_SLASH;
        case InputType::KEY_SEMICOLON:
            return GLFW_KEY_SEMICOLON;
        case InputType::KEY_EQUAL:
            return GLFW_KEY_EQUAL;
        case InputType::KEY_LEFT_BRACKET:
            return GLFW_KEY_LEFT_BRACKET;
        case InputType::KEY_BACKSLASH:
            return GLFW_KEY_BACKSLASH;
        case InputType::KEY_RIGHT_BRACKET:
            return GLFW_KEY_RIGHT_BRACKET;
        case InputType::KEY_GRAVE_ACCENT:
            return GLFW_KEY_GRAVE_ACCENT;
        case InputType::KEY_WORLD_1:
            return GLFW_KEY_WORLD_1;
        case InputType::KEY_WORLD_2:
            return GLFW_KEY_WORLD_2;
        case InputType::KEY_ESCAPE:
            return GLFW_KEY_ESCAPE;
        case InputType::KEY_ENTER:
            return GLFW_KEY_ENTER;
        case InputType::KEY_TAB:
            return GLFW_KEY_TAB;
        case InputType::KEY_BACKSPACE:
            return GLFW_KEY_BACKSPACE;
        case InputType::KEY_INSERT:
            return GLFW_KEY_INSERT;
        case InputType::KEY_DELETE:
            return GLFW_KEY_DELETE;
        case InputType::KEY_PAGE_UP:
            return GLFW_KEY_PAGE_UP;
        case InputType::KEY_PAGE_DOWN:
            return GLFW_KEY_PAGE_DOWN;
        case InputType::KEY_HOME:
            return GLFW_KEY_HOME;
        case InputType::KEY_END:
            return GLFW_KEY_END;
        case InputType::KEY_CAPS_LOCK:
            return GLFW_KEY_CAPS_LOCK;
        case InputType::KEY_SCROLL_LOCK:
            return GLFW_KEY_SCROLL_LOCK;
        case InputType::KEY_NUM_LOCK:
            return GLFW_KEY_NUM_LOCK;
        case InputType::KEY_PRINT_SCREEN:
            return GLFW_KEY_PRINT_SCREEN;
        case InputType::KEY_PAUSE:
            return GLFW_KEY_PAUSE;
        case InputType::KEY_MENU:
            return GLFW_KEY_MENU;
        case InputType::KEY_NUMPAD_DECIMAL:
            return GLFW_KEY_KP_DECIMAL;
        case InputType::KEY_NUMPAD_DIVIDE:
            return GLFW_KEY_KP_DIVIDE;
        case InputType::KEY_NUMPAD_MULTIPLY:
            return GLFW_KEY_KP_MULTIPLY;
        case InputType::KEY_NUMPAD_SUBTRACT:
            return GLFW_KEY_KP_SUBTRACT;
        case InputType::KEY_NUMPAD_ADD:
            return GLFW_KEY_KP_ADD;
        case InputType::KEY_NUMPAD_ENTER:
            return GLFW_KEY_KP_ENTER;
        case InputType::KEY_NUMPAD_EQUAL:
            return GLFW_KEY_KP_EQUAL;
        case InputType::KEY_NUMPAD_0:
            return GLFW_KEY_KP_0;
        case InputType::KEY_NUMPAD_1:
            return GLFW_KEY_KP_1;
        case InputType::KEY_NUMPAD_2:
            return GLFW_KEY_KP_2;
        case InputType::KEY_NUMPAD_3:
            return GLFW_KEY_KP_3;
        case InputType::KEY_NUMPAD_4:
            return GLFW_KEY_KP_4;
        case InputType::KEY_NUMPAD_5:
            return GLFW_KEY_KP_5;
        case InputType::KEY_NUMPAD_6:
            return GLFW_KEY_KP_6;
        case InputType::KEY_NUMPAD_7:
            return GLFW_KEY_KP_7;
        case InputType::KEY_NUMPAD_8:
            return GLFW_KEY_KP_8;
        case InputType::KEY_NUMPAD_9:
            return GLFW_KEY_KP_9;
        case InputType::MOUSE_BUTTON_1:
            return GLFW_MOUSE_BUTTON_1;
        case InputType::MOUSE_BUTTON_2:
            return GLFW_MOUSE_BUTTON_2;
        case InputType::MOUSE_BUTTON_3:
            return GLFW_MOUSE_BUTTON_3;
        case InputType::MOUSE_BUTTON_4:
            return GLFW_MOUSE_BUTTON_4;
        case InputType::MOUSE_BUTTON_5:
            return GLFW_MOUSE_BUTTON_5;
        case InputType::MOUSE_BUTTON_6:
            return GLFW_MOUSE_BUTTON_6;
        case InputType::MOUSE_BUTTON_7:
            return GLFW_MOUSE_BUTTON_7;
        case InputType::MOUSE_BUTTON_8:
            return GLFW_MOUSE_BUTTON_8;
        case InputType::MOUSE_BUTTON_LEFT:
            return GLFW_MOUSE_BUTTON_LEFT;
        case InputType::MOUSE_BUTTON_RIGHT:
            return GLFW_MOUSE_BUTTON_RIGHT;
        case InputType::MOUSE_BUTTON_MIDDLE:
            return GLFW_MOUSE_BUTTON_MIDDLE;
        case InputType::CONTROLLER_BUTTON_A:
            return GLFW_GAMEPAD_BUTTON_A;
        case InputType::CONTROLLER_BUTTON_B:
            return GLFW_GAMEPAD_BUTTON_B;
        case InputType::CONTROLLER_BUTTON_X:
            return GLFW_GAMEPAD_BUTTON_X;
        case InputType::CONTROLLER_BUTTON_Y:
            return GLFW_GAMEPAD_BUTTON_Y;
        case InputType::MOUSE_AXIS_SCROLL:
            break;
        case InputType::MOUSE_AXIS_HORIZONTAL:
            break;
        case InputType::MOUSE_AXIS_VERTICAL:
            break;
        case InputType::CONTROLLER_BUTTON_DPAD_LEFT:
            return GLFW_GAMEPAD_BUTTON_DPAD_LEFT;
        case InputType::CONTROLLER_BUTTON_DPAD_RIGHT:
            return GLFW_GAMEPAD_BUTTON_DPAD_RIGHT;
        case InputType::CONTROLLER_BUTTON_DPAD_UP:
            return GLFW_GAMEPAD_BUTTON_DPAD_UP;
        case InputType::CONTROLLER_BUTTON_DPAD_DOWN:
            return GLFW_GAMEPAD_BUTTON_DPAD_DOWN;
        case InputType::CONTROLLER_BUTTON_BUMPER_LEFT:
            return GLFW_GAMEPAD_BUTTON_LEFT_BUMPER;
        case InputType::CONTROLLER_BUTTON_BUMPER_RIGHT:
            return GLFW_GAMEPAD_BUTTON_RIGHT_BUMPER;
        case InputType::CONTROLLER_BUTTON_BACK:
            return GLFW_GAMEPAD_BUTTON_BACK;
        case InputType::CONTROLLER_BUTTON_START:
            return GLFW_GAMEPAD_BUTTON_START;
        case InputType::CONTROLLER_BUTTON_THUMB_LEFT:
            return GLFW_GAMEPAD_BUTTON_LEFT_THUMB;
        case InputType::CONTROLLER_BUTTON_THUMB_RIGHT:
            return GLFW_GAMEPAD_BUTTON_RIGHT_THUMB;
        case InputType::CONTROLLER_BUTTON_GUIDE:
            return GLFW_GAMEPAD_BUTTON_GUIDE;
        case InputType::CONTROLLER_AXIS_LEFT_X:
            return GLFW_GAMEPAD_AXIS_LEFT_X;
        case InputType::CONTROLLER_AXIS_LEFT_Y:
            return GLFW_GAMEPAD_AXIS_LEFT_Y;
        case InputType::CONTROLLER_AXIS_RIGHT_X:
            return GLFW_GAMEPAD_AXIS_RIGHT_X;
        case InputType::CONTROLLER_AXIS_RIGHT_Y:
            return GLFW_GAMEPAD_AXIS_RIGHT_Y;
        case InputType::CONTROLLER_AXIS_LEFT_TRIGGER:
            return GLFW_GAMEPAD_AXIS_LEFT_TRIGGER;
        case InputType::CONTROLLER_AXIS_RIGHT_TRIGGER:
            return GLFW_GAMEPAD_AXIS_RIGHT_TRIGGER;
    }
    throw std::runtime_error("Unrecognised input type: " + inputTypeToString(type));
}

ore::input::InputType ore::input::fromGLFWKeyboardEnum(int type) {
    switch(type) {
        case GLFW_KEY_A:
        	return InputType::KEY_A;            
        case GLFW_KEY_B:
        	return InputType::KEY_B;            
        case GLFW_KEY_C:
        	return InputType::KEY_C;            
        case GLFW_KEY_D:
        	return InputType::KEY_D;            
        case GLFW_KEY_E:
        	return InputType::KEY_E;            
        case GLFW_KEY_F:
        	return InputType::KEY_F;            
        case GLFW_KEY_G:
        	return InputType::KEY_G;            
        case GLFW_KEY_H:
        	return InputType::KEY_H;            
        case GLFW_KEY_I:
        	return InputType::KEY_I;            
        case GLFW_KEY_J:
        	return InputType::KEY_J;            
        case GLFW_KEY_K:
        	return InputType::KEY_K;            
        case GLFW_KEY_L:
        	return InputType::KEY_L;            
        case GLFW_KEY_M:
        	return InputType::KEY_M;            
        case GLFW_KEY_N:
        	return InputType::KEY_N;            
        case GLFW_KEY_O:
        	return InputType::KEY_O;            
        case GLFW_KEY_P:
        	return InputType::KEY_P;            
        case GLFW_KEY_Q:
        	return InputType::KEY_Q;            
        case GLFW_KEY_R:
        	return InputType::KEY_R;            
        case GLFW_KEY_S:
        	return InputType::KEY_S;            
        case GLFW_KEY_T:
        	return InputType::KEY_T;            
        case GLFW_KEY_U:
        	return InputType::KEY_U;            
        case GLFW_KEY_V:
        	return InputType::KEY_V;            
        case GLFW_KEY_W:
        	return InputType::KEY_W;            
        case GLFW_KEY_X:
        	return InputType::KEY_X;            
        case GLFW_KEY_Y:
        	return InputType::KEY_Y;            
        case GLFW_KEY_Z:
        	return InputType::KEY_Z;            
        case GLFW_KEY_0:
        	return InputType::KEY_0;            
        case GLFW_KEY_1:
        	return InputType::KEY_1;            
        case GLFW_KEY_2:
        	return InputType::KEY_2;            
        case GLFW_KEY_3:
        	return InputType::KEY_3;            
        case GLFW_KEY_4:
        	return InputType::KEY_4;            
        case GLFW_KEY_5:
        	return InputType::KEY_5;            
        case GLFW_KEY_6:
        	return InputType::KEY_6;            
        case GLFW_KEY_7:
        	return InputType::KEY_7;            
        case GLFW_KEY_8:
        	return InputType::KEY_8;            
        case GLFW_KEY_9:
        	return InputType::KEY_9;            
        case GLFW_KEY_F1:
        	return InputType::KEY_F1;            
        case GLFW_KEY_F2:
        	return InputType::KEY_F2;            
        case GLFW_KEY_F3:
        	return InputType::KEY_F3;            
        case GLFW_KEY_F4:
        	return InputType::KEY_F4;            
        case GLFW_KEY_F5:
        	return InputType::KEY_F5;            
        case GLFW_KEY_F6:
        	return InputType::KEY_F6;            
        case GLFW_KEY_F7:
        	return InputType::KEY_F7;            
        case GLFW_KEY_F8:
        	return InputType::KEY_F8;            
        case GLFW_KEY_F9:
        	return InputType::KEY_F9;            
        case GLFW_KEY_F10:
        	return InputType::KEY_F10;            
        case GLFW_KEY_F11:
        	return InputType::KEY_F11;            
        case GLFW_KEY_F12:
        	return InputType::KEY_F12;            
        case GLFW_KEY_F13:
        	return InputType::KEY_F13;            
        case GLFW_KEY_F14:
        	return InputType::KEY_F14;            
        case GLFW_KEY_F15:
        	return InputType::KEY_F15;            
        case GLFW_KEY_F16:
        	return InputType::KEY_F16;            
        case GLFW_KEY_F17:
        	return InputType::KEY_F17;            
        case GLFW_KEY_F18:
        	return InputType::KEY_F18;            
        case GLFW_KEY_F19:
        	return InputType::KEY_F19;            
        case GLFW_KEY_F20:
        	return InputType::KEY_F20;            
        case GLFW_KEY_F21:
        	return InputType::KEY_F21;            
        case GLFW_KEY_F22:
        	return InputType::KEY_F22;            
        case GLFW_KEY_F23:
        	return InputType::KEY_F23;            
        case GLFW_KEY_F24:
        	return InputType::KEY_F24;            
        case GLFW_KEY_F25:
        	return InputType::KEY_F25;            
        case GLFW_KEY_LEFT:
        	return InputType::KEY_LEFT;            
        case GLFW_KEY_RIGHT:
        	return InputType::KEY_RIGHT;            
        case GLFW_KEY_UP:
        	return InputType::KEY_UP;            
        case GLFW_KEY_DOWN:
        	return InputType::KEY_DOWN;            
        case GLFW_KEY_LEFT_SHIFT:
        	return InputType::KEY_LEFT_SHIFT;            
        case GLFW_KEY_RIGHT_SHIFT:
        	return InputType::KEY_RIGHT_SHIFT;            
        case GLFW_KEY_LEFT_CONTROL:
        	return InputType::KEY_LEFT_CONTROL;            
        case GLFW_KEY_RIGHT_CONTROL:
        	return InputType::KEY_RIGHT_CONTROL;            
        case GLFW_KEY_LEFT_ALT:
        	return InputType::KEY_LEFT_ALT;            
        case GLFW_KEY_RIGHT_ALT:
        	return InputType::KEY_RIGHT_ALT;            
        case GLFW_KEY_LEFT_SUPER:
        	return InputType::KEY_LEFT_SUPER;            
        case GLFW_KEY_RIGHT_SUPER:
        	return InputType::KEY_RIGHT_SUPER;            
        case GLFW_KEY_SPACE:
        	return InputType::KEY_SPACE;            
        case GLFW_KEY_APOSTROPHE:
        	return InputType::KEY_APOSTROPHE;            
        case GLFW_KEY_COMMA:
        	return InputType::KEY_COMMA;            
        case GLFW_KEY_PERIOD:
        	return InputType::KEY_PERIOD;            
        case GLFW_KEY_SLASH:
        	return InputType::KEY_SLASH;            
        case GLFW_KEY_SEMICOLON:
        	return InputType::KEY_SEMICOLON;            
        case GLFW_KEY_EQUAL:
        	return InputType::KEY_EQUAL;            
        case GLFW_KEY_LEFT_BRACKET:
        	return InputType::KEY_LEFT_BRACKET;            
        case GLFW_KEY_BACKSLASH:
        	return InputType::KEY_BACKSLASH;            
        case GLFW_KEY_RIGHT_BRACKET:
        	return InputType::KEY_RIGHT_BRACKET;            
        case GLFW_KEY_GRAVE_ACCENT:
        	return InputType::KEY_GRAVE_ACCENT;            
        case GLFW_KEY_WORLD_1:
        	return InputType::KEY_WORLD_1;            
        case GLFW_KEY_WORLD_2:
        	return InputType::KEY_WORLD_2;            
        case GLFW_KEY_ESCAPE:
        	return InputType::KEY_ESCAPE;            
        case GLFW_KEY_ENTER:
        	return InputType::KEY_ENTER;            
        case GLFW_KEY_TAB:
        	return InputType::KEY_TAB;            
        case GLFW_KEY_BACKSPACE:
        	return InputType::KEY_BACKSPACE;            
        case GLFW_KEY_INSERT:
        	return InputType::KEY_INSERT;            
        case GLFW_KEY_DELETE:
        	return InputType::KEY_DELETE;            
        case GLFW_KEY_PAGE_UP:
        	return InputType::KEY_PAGE_UP;            
        case GLFW_KEY_PAGE_DOWN:
        	return InputType::KEY_PAGE_DOWN;            
        case GLFW_KEY_HOME:
        	return InputType::KEY_HOME;            
        case GLFW_KEY_END:
        	return InputType::KEY_END;            
        case GLFW_KEY_CAPS_LOCK:
        	return InputType::KEY_CAPS_LOCK;            
        case GLFW_KEY_SCROLL_LOCK:
        	return InputType::KEY_SCROLL_LOCK;            
        case GLFW_KEY_NUM_LOCK:
        	return InputType::KEY_NUM_LOCK;            
        case GLFW_KEY_PRINT_SCREEN:
        	return InputType::KEY_PRINT_SCREEN;            
        case GLFW_KEY_PAUSE:
        	return InputType::KEY_PAUSE;            
        case GLFW_KEY_MENU:
        	return InputType::KEY_MENU;            
        case GLFW_KEY_KP_DECIMAL:
        	return InputType::KEY_NUMPAD_DECIMAL;            
        case GLFW_KEY_KP_DIVIDE:
        	return InputType::KEY_NUMPAD_DIVIDE;            
        case GLFW_KEY_KP_MULTIPLY:
        	return InputType::KEY_NUMPAD_MULTIPLY;            
        case GLFW_KEY_KP_SUBTRACT:
        	return InputType::KEY_NUMPAD_SUBTRACT;            
        case GLFW_KEY_KP_ADD:
        	return InputType::KEY_NUMPAD_ADD;            
        case GLFW_KEY_KP_ENTER:
        	return InputType::KEY_NUMPAD_ENTER;            
        case GLFW_KEY_KP_EQUAL:
        	return InputType::KEY_NUMPAD_EQUAL;            
        case GLFW_KEY_KP_0:
        	return InputType::KEY_NUMPAD_0;            
        case GLFW_KEY_KP_1:
        	return InputType::KEY_NUMPAD_1;            
        case GLFW_KEY_KP_2:
        	return InputType::KEY_NUMPAD_2;            
        case GLFW_KEY_KP_3:
        	return InputType::KEY_NUMPAD_3;            
        case GLFW_KEY_KP_4:
        	return InputType::KEY_NUMPAD_4;            
        case GLFW_KEY_KP_5:
        	return InputType::KEY_NUMPAD_5;            
        case GLFW_KEY_KP_6:
        	return InputType::KEY_NUMPAD_6;            
        case GLFW_KEY_KP_7:
        	return InputType::KEY_NUMPAD_7;            
        case GLFW_KEY_KP_8:
        	return InputType::KEY_NUMPAD_8;            
        case GLFW_KEY_KP_9:
        	return InputType::KEY_NUMPAD_9;
        default:
            throw std::runtime_error("GLFW Keyboard key enum value was not recognised");
    }
}

ore::input::InputType ore::input::fromGLFWMouseEnum(int type) {
    switch(type) {
        case GLFW_MOUSE_BUTTON_LEFT:
            return InputType::MOUSE_BUTTON_LEFT;
        case GLFW_MOUSE_BUTTON_RIGHT:
            return InputType::MOUSE_BUTTON_RIGHT;
        case GLFW_MOUSE_BUTTON_MIDDLE:
            return InputType::MOUSE_BUTTON_MIDDLE;
        case GLFW_MOUSE_BUTTON_4:
            return InputType::MOUSE_BUTTON_4;
        case GLFW_MOUSE_BUTTON_5:
            return InputType::MOUSE_BUTTON_5;
        case GLFW_MOUSE_BUTTON_6:
            return InputType::MOUSE_BUTTON_6;
        case GLFW_MOUSE_BUTTON_7:
            return InputType::MOUSE_BUTTON_7;
        case GLFW_MOUSE_BUTTON_8:
            return InputType::MOUSE_BUTTON_8;
        default:
            throw std::runtime_error("GLFW Mouse button enum value was not recognised");
    }
}

ore::input::InputType ore::input::fromGLFWGamepadButtonEnum(int type) {
    switch(type) {
        case GLFW_GAMEPAD_BUTTON_A:
            return InputType::CONTROLLER_BUTTON_A;
        case GLFW_GAMEPAD_BUTTON_B:
            return InputType::CONTROLLER_BUTTON_B;
        case GLFW_GAMEPAD_BUTTON_X:
            return InputType::CONTROLLER_BUTTON_X;
        case GLFW_GAMEPAD_BUTTON_Y:
            return InputType::CONTROLLER_BUTTON_Y;
        case GLFW_GAMEPAD_BUTTON_DPAD_LEFT:
            return InputType::CONTROLLER_BUTTON_DPAD_LEFT;
        case GLFW_GAMEPAD_BUTTON_DPAD_RIGHT:
            return InputType::CONTROLLER_BUTTON_DPAD_RIGHT;
        case GLFW_GAMEPAD_BUTTON_DPAD_UP:
            return InputType::CONTROLLER_BUTTON_DPAD_UP;
        case GLFW_GAMEPAD_BUTTON_DPAD_DOWN:
            return InputType::CONTROLLER_BUTTON_DPAD_DOWN;
        case GLFW_GAMEPAD_BUTTON_LEFT_BUMPER:
            return InputType::CONTROLLER_BUTTON_BUMPER_LEFT;
        case GLFW_GAMEPAD_BUTTON_RIGHT_BUMPER:
            return InputType::CONTROLLER_BUTTON_BUMPER_RIGHT;
        case GLFW_GAMEPAD_BUTTON_BACK:
            return InputType::CONTROLLER_BUTTON_BACK;
        case GLFW_GAMEPAD_BUTTON_START:
            return InputType::CONTROLLER_BUTTON_START;
        case GLFW_GAMEPAD_BUTTON_LEFT_THUMB:
            return InputType::CONTROLLER_BUTTON_THUMB_LEFT;
        case GLFW_GAMEPAD_BUTTON_RIGHT_THUMB:
            return InputType::CONTROLLER_BUTTON_THUMB_RIGHT;
        case GLFW_GAMEPAD_BUTTON_GUIDE:
            return InputType::CONTROLLER_BUTTON_GUIDE;
        default:
            throw std::runtime_error("GLFW Gamepad button enum value was not recognised");
    }
}

ore::input::InputType ore::input::fromGLFWGamepadAxisEnum(int type) {
    switch(type) {
        case GLFW_GAMEPAD_AXIS_LEFT_X:
            return InputType::CONTROLLER_AXIS_LEFT_X;
        case GLFW_GAMEPAD_AXIS_LEFT_Y:
            return InputType::CONTROLLER_AXIS_LEFT_Y;
        case GLFW_GAMEPAD_AXIS_RIGHT_X:
            return InputType::CONTROLLER_AXIS_RIGHT_X;
        case GLFW_GAMEPAD_AXIS_RIGHT_Y:
            return InputType::CONTROLLER_AXIS_RIGHT_Y;
        case GLFW_GAMEPAD_AXIS_LEFT_TRIGGER:
            return InputType::CONTROLLER_AXIS_LEFT_TRIGGER;
        case GLFW_GAMEPAD_AXIS_RIGHT_TRIGGER:
            return InputType::CONTROLLER_AXIS_RIGHT_TRIGGER;
        default:
            throw std::runtime_error("GLFW Gamepad axis enum value was not recognised");
    }
}
