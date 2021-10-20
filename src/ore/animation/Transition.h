#pragma once
#include "TransitionType.h"

namespace ore {
    struct Transition {
        TransitionType type = TransitionType::INSTANT;
        float durationSeconds = 0;
    };
}