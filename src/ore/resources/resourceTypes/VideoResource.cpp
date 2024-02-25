#include "VideoResource.h"

void ore::resources::VideoResource::load(const ore::filesystem::path &fileLocation) {
    this->targetFile = fileLocation;
}

bool ore::resources::VideoResource::requiresMainThread() {
    return false;
}

void ore::resources::VideoResource::completeLoadOnMainThread() {}
void ore::resources::VideoResource::destroy() {}

std::filesystem::path ore::resources::VideoResource::getVideoFileLocation() {
    return this->targetFile;
}
