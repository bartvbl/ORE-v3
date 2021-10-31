#include "FreePerspectiveCameraController.h"

const float rotationSpeed = 0.08f;
const float cameraSpeed = 0.03f;

void ore::FreePerspectiveCameraController::update() {
    float deltaX = movementX;
    float deltaY = -1 * movementY;
    //float deltaRotationX = std::abs(axes[3]) > 0.3 ? axes[3] : 0;
    //float deltaRotationY = std::abs(axes[4]) > 0.3 ? -1.0f * axes[4] : 0;

    //if (std::abs(deltaRotationX) < 0.15) { deltaRotationX = 0; }
    //if (std::abs(deltaRotationY) < 0.15) { deltaRotationY = 0; }
    if (std::abs(deltaX) < 0.15) { deltaX = 0; }
    if (std::abs(deltaY) < 0.15) { deltaY = 0; }

    //camera->rotation.x += deltaRotationX * rotationSpeed;
    //camera->rotation.y -= deltaRotationY * rotationSpeed;

    float angleYRadiansForward = camera->rotation.x;
    float angleYRadiansSideways = (camera->rotation.x + float(M_PI / 2.0));

    camera->position.x -= deltaY * std::sin(angleYRadiansForward) * cameraSpeed;
    camera->position.z += deltaY * std::cos(angleYRadiansForward) * cameraSpeed;

    camera->position.x -= deltaX * std::sin(angleYRadiansSideways) * cameraSpeed;;
    camera->position.z += deltaX * std::cos(angleYRadiansSideways) * cameraSpeed;

    camera->position.y += (((movementUp + 1.0f) / 2.0f) - ((movementDown + 1.0f) / 2.0f)) * cameraSpeed;
}
