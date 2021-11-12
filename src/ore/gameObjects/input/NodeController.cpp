#include "NodeController.h"

const float rotationSpeed = 2.5f;
const float cameraSpeed = 0.03f;
// Controller specific, but because keyboard inputs are binary it automatically doesn't apply to those
const float deadZone = 0.3;

float applyDeadzone(float input) {
    return std::abs(input) > deadZone ? input : 0;
}

void ore::NodeController::update() {
    float horizontalRotation = applyDeadzone(lookHorizontal);
    float verticalRotation = applyDeadzone(lookVertical);

    node->rotation.y += horizontalRotation * rotationSpeed;
    node->rotation.x += verticalRotation * rotationSpeed;

    float angleYRadiansForward = glm::radians(node->rotation.y);
    float angleYRadiansSideways = (glm::radians(node->rotation.y) + float(M_PI / 2.0));

    float moveRight = applyDeadzone(movementRight) - applyDeadzone(movementLeft);
    float moveForward = applyDeadzone(movementForward) - applyDeadzone(movementBackward);

    node->position.x += moveForward * std::sin(angleYRadiansForward) * cameraSpeed;
    node->position.z -= moveForward * std::cos(angleYRadiansForward) * cameraSpeed;

    node->position.x -= moveRight * std::sin(angleYRadiansSideways) * cameraSpeed;;
    node->position.z += moveRight * std::cos(angleYRadiansSideways) * cameraSpeed;

    node->position.y += (movementDown - movementUp) * cameraSpeed;
}
