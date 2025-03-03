#include "SoundResource.h"

void ore::resources::SoundResource::load(const ore::filesystem::path &fileLocation) {
    ma_result result = ma_decoder_init_file(fileLocation.string().c_str(), nullptr, &decoder);
    if (result != MA_SUCCESS) {
        throw std::runtime_error("Failed to load audio file located at " + fileLocation.string());
    }
}

bool ore::resources::SoundResource::requiresMainThread() {
    return false;
}

void ore::resources::SoundResource::completeLoadOnMainThread() {

}

void ore::resources::SoundResource::destroy() {
    ma_decoder_uninit(&decoder);
}