#include <chrono>
#include "AnimationService.h"



// Calculates the elapsed time since the previous time this function was called.
double ore::AnimationService::getTimeDeltaSeconds() {
    // Determine the current time
    std::chrono::steady_clock::time_point currentTime = std::chrono::steady_clock::now();

    // Calculate the number of nanoseconds that elapsed since the previous call to this function
    long long timeDelta = std::chrono::duration_cast<std::chrono::nanoseconds>(currentTime - previousTimePoint).count();
    // Convert the time delta in nanoseconds to seconds
    double timeDeltaSeconds = (double)timeDelta / 1000000000.0;

    // Store the previously measured current time
    previousTimePoint = currentTime;

    // Return the calculated time delta in seconds
    return timeDeltaSeconds;
}

void ore::AnimationService::init() {

}

void ore::AnimationService::update() {
    double timeDeltaSeconds = getTimeDeltaSeconds();
    for(int i = 0; i < playingAnimations.size(); i++) {
        bool animationComplete = playingAnimations.at(i).animate(timeDeltaSeconds);
        if(animationComplete) {
            playingAnimations.erase(playingAnimations.begin() + i);
            i--;
        }
    }
}

void ore::AnimationService::animate(ore::scene::CoordinateNode *node, ore::Transition transition, ore::RelativeTransformation destination) {
    playingAnimations.emplace_back(node, destination, transition);
}
