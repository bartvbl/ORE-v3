#include <glm/gtc/matrix_transform.hpp>
#include <glad/glad.h>
#include "OrthographicCamera.h"

void ore::scene::OrthographicCamera::render(ore::RenderState &renderState) {
    glm::mat4 previousViewMatrix = renderState.transformations.view;
    glm::mat4 previousProjectionMatrix = renderState.transformations.projection;

    renderState.transformations.projection = glm::ortho(left, right, bottom, top, zNear, zFar);

    // Camera allows itself to be attached to another node
    glm::mat4 relativeMatrix = glm::inverse(renderState.transformations.model);

    glm::mat4 positionTransformation(1.0);
    positionTransformation *= glm::rotate(glm::mat4(1.0), glm::radians(rotation.z), glm::vec3(0, 0, 1));
    positionTransformation *= glm::rotate(glm::mat4(1.0), glm::radians(rotation.x), glm::vec3(1, 0, 0));
    positionTransformation *= glm::rotate(glm::mat4(1.0), glm::radians(rotation.y), glm::vec3(0, 1, 0));
    positionTransformation *= glm::translate(glm::mat4(1.0), position);

    renderState.transformations.view = relativeMatrix * positionTransformation;

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
