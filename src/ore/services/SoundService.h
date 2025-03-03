#pragma once
#include <ore/resources/resourceTypes/SoundResource.h>
#include "miniaudio.h"

namespace ore {
    class SoundService {
        ma_engine engine;

        static constexpr uint32_t channelCount = 2;

    public:
        void init();
        void shutdown();

        void playSound(ore::resources::SoundResource* sound);
    };
}

