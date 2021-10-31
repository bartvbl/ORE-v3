#include "NodeController.h"

const float rotationSpeed = 0.08f;
const float cameraSpeed = 0.03f;
const float deadZone = 0.3;

void ore::NodeController::update() {
    float horizontalRotation = (std::abs(lookHorizontal) > deadZone) ? lookHorizontal : 0;
    float verticalRotation = (std::abs(lookVertical) > deadZone) ? lookVertical : 0;

    node->rotation.y += horizontalRotation * rotationSpeed;
    node->rotation.x += verticalRotation * rotationSpeed;

    float angleYRadiansForward = node->rotation.y;
    float angleYRadiansSideways = (node->rotation.y + float(M_PI / 2.0));

    float moveRight = (std::abs(movementX) > deadZone) ? movementX : 0;
    float moveForward = (std::abs(movementY) > deadZone) ? movementY : 0;

    node->position.x += moveForward * std::sin(angleYRadiansForward) * cameraSpeed;
    node->position.z -= moveForward * std::cos(angleYRadiansForward) * cameraSpeed;

    node->position.x -= moveRight * std::sin(angleYRadiansSideways) * cameraSpeed;;
    node->position.z += moveRight * std::cos(angleYRadiansSideways) * cameraSpeed;

    node->position.y += (movementDown - movementUp) * cameraSpeed;
}
