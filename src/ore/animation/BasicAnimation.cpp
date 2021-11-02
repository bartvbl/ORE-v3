//
// Created by bart on 02.11.2021.
//

#include "BasicAnimation.h"
#include "Transition.h"

bool ore::animation::BasicAnimation::animate(double timeDelta) {
    this->progressionSeconds += timeDelta;

    float unboundedFractionComplete = transition.durationSeconds == 0 ? 1 : progressionSeconds / transition.durationSeconds;
    float fractionComplete = std::min<float>(1.0f, unboundedFractionComplete);
    ore::RelativeTransformation delta;
    delta.position = end.position - start.position;
    delta.rotation = end.rotation - start.rotation;
    delta.scale = end.scale - start.scale;

    const float n1 = 7.5625;
    const float d1 = 2.75;

    switch (transition.type) {
        case ore::TransitionType::INSTANT:
            target->position = end.position;
            target->rotation = end.rotation;
            target->scale = glm::vec3(end.scale, end.scale, end.scale);
            return true;
        case ore::TransitionType::EASE_IN:
            fractionComplete = 1 - pow(1 - fractionComplete, 3);
            break;
        case ore::TransitionType::EASE_IN_OUT:
            fractionComplete = fractionComplete < 0.5
                               ? 16.0f * fractionComplete * fractionComplete * fractionComplete * fractionComplete *
                                 fractionComplete
                               : 1.0f - pow(-2.0f * fractionComplete + 2.0f, 5.0f) / 2.0f;
            break;
        case ore::TransitionType::EASE_OUT:
            fractionComplete = pow(fractionComplete, 3);
            break;
        case ore::TransitionType::EASE_IN_BOUNCE:
            if (fractionComplete < 1 / d1) {
                fractionComplete = n1 * fractionComplete * fractionComplete;
            } else if (fractionComplete < 2 / d1) {
                fractionComplete = n1 * (fractionComplete -= 1.5 / d1) * fractionComplete + 0.75;
            } else if (fractionComplete < 2.5 / d1) {
                fractionComplete = n1 * (fractionComplete -= 2.25 / d1) * fractionComplete + 0.9375;
            } else {
                fractionComplete = n1 * (fractionComplete -= 2.625 / d1) * fractionComplete + 0.984375;
            }
            break;
        case ore::TransitionType::LINEAR:
            // No change
            break;
    }

    target->position = start.position + delta.position * fractionComplete;
    target->rotation = start.rotation + delta.rotation * fractionComplete;
    float newScale = start.scale + delta.scale * fractionComplete;
    target->scale = glm::vec3(newScale, newScale, newScale);

    return unboundedFractionComplete >= 1;
}
