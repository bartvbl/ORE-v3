#include <iostream>
#include "TextureResource.h"

void ore::resources::TextureResource::load(const ore::filesystem::path &fileLocation) {
    std::cout << "Loading texture from " + fileLocation.string() + "\n" << std::flush;
}

bool ore::resources::TextureResource::requiresMainThread() {
    return true;
}

void ore::resources::TextureResource::completeLoadOnMainThread() {
    std::cout << "Completing texture on main thread!\n" << std::flush;
}

void ore::resources::TextureResource::destroy() {

}
