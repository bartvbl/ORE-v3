#include <g3log/g3log.hpp>
#include "InputEventTriggerType.h"

ore::input::InputEventTriggerType ore::input::parseEventTriggerType(std::string triggerTypeString) {
    if(triggerTypeString == "onFrameStart") {
        return InputEventTriggerType::ON_FRAME_START;
    } else if(triggerTypeString == "onChange") {
        return InputEventTriggerType::ON_CHANGE;
    } else if(triggerTypeString == "onPress") {
        return InputEventTriggerType::ON_PRESS;
    } else if(triggerTypeString == "onHold") {
        return InputEventTriggerType::ON_HOLD;
    } else if(triggerTypeString == "onRelease") {
        return InputEventTriggerType::ON_RELEASE;
    } else if(triggerTypeString == "onIncreasing") {
        return InputEventTriggerType::ON_INCREASING;
    } else if(triggerTypeString == "onDecreasing") {
        return InputEventTriggerType::ON_DECREASING;
    } else {
        LOG(FATAL) << "Invalid input event trigger type specified: " << triggerTypeString << std::endl;
    }
}
