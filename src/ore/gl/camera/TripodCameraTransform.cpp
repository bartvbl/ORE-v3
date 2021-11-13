#include <glm/gtx/transform.hpp>
#include "TripodCameraTransform.h"

glm::mat4 ore::gl::computeTripodViewTransformation(glm::vec3 position, glm::vec3 rotation) {
    glm::mat4 positionTransformation(1.0);
    positionTransformation *= glm::rotate(glm::mat4(1.0), glm::radians(rotation.z), glm::vec3(0, 0, 1));
    positionTransformation *= glm::rotate(glm::mat4(1.0), glm::radians(rotation.x), glm::vec3(1, 0, 0));
    positionTransformation *= glm::rotate(glm::mat4(1.0), glm::radians(rotation.y), glm::vec3(0, 1, 0));
    positionTransformation *= glm::translate(glm::mat4(1.0), position);
}
