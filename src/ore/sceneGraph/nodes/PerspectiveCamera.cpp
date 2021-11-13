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

    renderState.transformations.view = ore::gl::computeTripodViewTransformation(renderState.transformations.model, position, rotation);

    CoordinateNode::render(renderState);

    renderState.transformations.view = previousViewMatrix;
    renderState.transformations.projection = previousProjectionMatrix;

    // Disable default behaviour: modifies model matrix
    //CoordinateNode::postRender(renderState);
}