#include <glm/gtc/matrix_transform.hpp>
#include "OrthographicCamera.h"

void ore::scene::OrthographicCamera::update(ore::RenderState &renderState) {
    renderState.transformations.projection = glm::ortho(left, right, bottom, top, zNear, zFar);

    SceneNode::update(renderState);
}
