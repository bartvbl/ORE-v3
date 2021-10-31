#include <glm/gtc/matrix_transform.hpp>
#include "PerspectiveCamera.h"

void ore::scene::PerspectiveCamera::render(ore::RenderState &renderState) {
    glm::mat4 previousViewMatrix = renderState.transformations.view;
    glm::mat4 previousProjectionMatrix = renderState.transformations.projection;

    float aspectRatio = float(renderState.window.width) / float(renderState.window.height);
    renderState.transformations.projection = glm::perspective(glm::radians(fovY), aspectRatio, zNear, zFar);

    // Camera allows itself to be
    glm::mat4 relativeMatrix = glm::inverse(renderState.transformations.model);

    glm::mat4 positionTransformation(1.0);
    positionTransformation = glm::rotate(positionTransformation, rotation.z, glm::vec3(0, 0, 1));
    positionTransformation = glm::rotate(positionTransformation, rotation.x, glm::vec3(1, 0, 0));
    positionTransformation = glm::rotate(positionTransformation, rotation.y, glm::vec3(0, 1, 0));
    positionTransformation = glm::translate(positionTransformation, position.asglm());




    renderState.transformations.view = relativeMatrix * positionTransformation;

    SceneNode::render(renderState);

    renderState.transformations.view = previousViewMatrix;
    renderState.transformations.projection = previousProjectionMatrix;
}