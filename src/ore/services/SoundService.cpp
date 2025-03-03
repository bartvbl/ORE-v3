
#include <c++/11/iostream>
#include "SoundService.h"
#include "miniaudio.h"

void ore::SoundService::init() {
    ma_engine_config engineConfig = ma_engine_config_init();
    ma_result result = ma_engine_init(nullptr, &engine);
    if (result != MA_SUCCESS) {
        throw std::runtime_error("Failed to create audio context!");
    }
}

void ore::SoundService::playSound(ore::resources::SoundResource *sound) {
    if(sound == nullptr) {
        throw std::runtime_error("Invalid sound!");
    }

    ma_engine_play_sound(&engine, sound->location.c_str(), NULL);

}

void ore::SoundService::shutdown() {
    ma_engine_uninit(&engine);
}
