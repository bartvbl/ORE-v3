#include <glm/gtc/matrix_transform.hpp>
#include "OrthographicCamera.h"

void ore::scene::OrthographicCamera::render(ore::RenderState &renderState) {
    renderState.transformations.projection = glm::ortho(left, right, bottom, top, zNear, zFar);

    SceneNode::render(renderState);
}
