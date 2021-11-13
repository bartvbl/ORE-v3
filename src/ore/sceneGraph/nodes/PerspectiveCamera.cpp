#include <glm/gtc/matrix_transform.hpp>
#include "PerspectiveCamera.h"
#include <ore/gl/camera/TripodCameraTransform.h>

void ore::scene::PerspectiveCamera::render(ore::RenderState &renderState) {
    // Disable default behaviour: modifies model matrix
    // CoordinateNode::preRender(renderState);

    glm::mat4 previousViewMatrix = renderState.transformations.view;
    glm::mat4 previousProjectionMatrix = renderState.transformations.projection;

    float aspectRatio = float(renderState.window.width) / float(renderState.window.height);
    renderState.transformations.projection = glm::perspective(glm::radians(fovY), aspectRatio, zNear, zFar);

    // Camera allows itself to be attached to another node
    glm::mat4 relativeMatrix = glm::inverse(renderState.transformations.model);

    glm::mat4 positionTransformation = ore::gl::computeTripodViewTransformation(position, rotation);

    renderState.transformations.view = relativeMatrix * positionTransformation;

    CoordinateNode::render(renderState);

    renderState.transformations.view = previousViewMatrix;
    renderState.transformations.projection = previousProjectionMatrix;

    // Disable default behaviour: modifies model matrix
    //CoordinateNode::postRender(renderState);
}