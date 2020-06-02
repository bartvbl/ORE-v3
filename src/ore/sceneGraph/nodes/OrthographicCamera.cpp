#include <glm/gtc/matrix_transform.hpp>
#include "OrthographicCamera.h"

void ore::scene::OrthographicCamera::preUpdate(ore::RenderState &renderState) {
    renderState.transformations.projection = glm::ortho(left, right, bottom, top, zNear, zFar);
}
