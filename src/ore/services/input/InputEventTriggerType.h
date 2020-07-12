#pragma once

namespace ore {
    namespace input {
        enum class InputEventTriggerType {
            ON_FRAME_UPDATE,
            ON_CHANGE,
            ON_PRESS,
            ON_RELEASE,
            ON_INCREASING,
            ON_DECREASING,
        };
    }
}