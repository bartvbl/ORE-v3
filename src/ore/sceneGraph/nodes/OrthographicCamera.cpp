#include <glm/gtc/matrix_transform.hpp>
#include <glad/glad.h>
#include "OrthographicCamera.h"
#include <ore/gl/camera/TripodCameraTransform.h>

void ore::scene::OrthographicCamera::render(ore::RenderState &renderState) {
    glm::mat4 previousViewMatrix = renderState.transformations.view;
    glm::mat4 previousProjectionMatrix = renderState.transformations.projection;

    renderState.transformations.projection = glm::ortho(left, right, bottom, top, zNear, zFar);

    renderState.transformations.view = ore::gl::computeTripodViewTransformation(renderState.transformations.model, position, rotation);

    if(depthTestingEnabled) {
        glEnable(GL_DEPTH_TEST);
    } else {
        glDisable(GL_DEPTH_TEST);
    }

    CoordinateNode::render(renderState);

    glEnable(GL_DEPTH_TEST);
    renderState.transformations.view = previousViewMatrix;
    renderState.transformations.projection = previousProjectionMatrix;
}

void ore::scene::OrthographicCamera::setBounds(float _left, float _right, float _bottom, float _top, float _near, float _far) {
    this->left = _left;
    this->right = _right;
    this->bottom = _bottom;
    this->top = _top;
    this->zNear = _near;
    this->zFar = _far;
}

void ore::scene::OrthographicCamera::setDepthTestingEnabled(bool enabled) {
    this->depthTestingEnabled = enabled;
}
