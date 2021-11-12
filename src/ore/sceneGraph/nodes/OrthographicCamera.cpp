#include <glm/gtc/matrix_transform.hpp>
#include "OrthographicCamera.h"

void ore::scene::OrthographicCamera::render(ore::RenderState &renderState) {
    glm::mat4 currentProjectionMatrix = renderState.transformations.projection;
    renderState.transformations.projection = glm::ortho(left, right, bottom, top, zNear, zFar);

    ContainerNode::render(renderState);
    renderState.transformations.projection = currentProjectionMatrix;
}

void ore::scene::OrthographicCamera::setBounds(float _left, float _right, float _bottom, float _top, float _near, float _far) {
    this->left = _left;
    this->right = _right;
    this->bottom = _bottom;
    this->top = _top;
    this->zNear = _near;
    this->zFar = _far;
}
