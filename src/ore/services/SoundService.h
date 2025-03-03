#pragma once
#include <ore/resources/resourceTypes/SoundResource.h>
#include "miniaudio.h"

namespace ore {
    class SoundService {
        ma_context context;
        ma_device device;

        std::vector<ore::resources::SoundResource*> playingSounds;
        static constexpr uint32_t channelCount = 2;

        friend void data_callback(ma_device* pDevice, void* pOutput, const void* pInput, ma_uint32 frameCount);
        friend uint32_t read_and_mix_pcm_frames_f32(ma_decoder* pDecoder, float* pOutputF32, ma_uint32 frameCount, ore::SoundService* soundService);

    public:
        void init();
        void shutdown();

        void playSound(ore::resources::SoundResource* sound);
    };
}

