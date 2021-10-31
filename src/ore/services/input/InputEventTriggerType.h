#pragma once

#include <string>

namespace ore {
    namespace input {
        enum class InputEventTriggerType {
            ON_FRAME_START,
            ON_CHANGE,
            ON_PRESS,
            ON_HOLD,
            ON_RELEASE,
            ON_INCREASING,
            ON_DECREASING
        };

        InputEventTriggerType parseEventTriggerType(std::string triggerTypeString);
    }
}