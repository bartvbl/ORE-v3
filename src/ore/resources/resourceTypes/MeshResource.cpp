#include <iostream>
#include <thread>
#include "MeshResource.h"

void ore::resources::MeshResource::load(const ore::filesystem::path &fileLocation) {
    std::cout << "Loading resource from " + fileLocation.string() + "\n" << std::flush;
    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout << "Loading resource from " + fileLocation.string() + " complete.\n" << std::flush;
}

bool ore::resources::MeshResource::requiresMainThread() {
    return true;
}

void ore::resources::MeshResource::completeLoadOnMainThread() {
    std::cout << "Completing resource on main thread!" << std::endl;
}
