#include "NodeController.h"

const float rotationSpeed = 0.08f;
const float cameraSpeed = 0.03f;

void ore::NodeController::update() {
    float deltaX = movementX;
    float deltaY = -1 * movementY;
    float deltaRotationX = std::abs(lookHorizontal) > 0.3 ? lookHorizontal : 0;
    float deltaRotationY = std::abs(lookVertical) > 0.3 ? -1.0f * lookVertical : 0;

    if (std::abs(deltaRotationX) < 0.15) { deltaRotationX = 0; }
    if (std::abs(deltaRotationY) < 0.15) { deltaRotationY = 0; }
    if (std::abs(deltaX) < 0.15) { deltaX = 0; }
    if (std::abs(deltaY) < 0.15) { deltaY = 0; }

    node->rotation.x += deltaRotationX * rotationSpeed;
    node->rotation.y -= deltaRotationY * rotationSpeed;

    float angleYRadiansForward = node->rotation.x;
    float angleYRadiansSideways = (node->rotation.x + float(M_PI / 2.0));

    node->position.x -= deltaY * std::sin(angleYRadiansForward) * cameraSpeed;
    node->position.z += deltaY * std::cos(angleYRadiansForward) * cameraSpeed;

    node->position.x -= deltaX * std::sin(angleYRadiansSideways) * cameraSpeed;;
    node->position.z += deltaX * std::cos(angleYRadiansSideways) * cameraSpeed;

    node->position.y += (((movementUp + 1.0f) / 2.0f) - ((movementDown + 1.0f) / 2.0f)) * cameraSpeed;
}
