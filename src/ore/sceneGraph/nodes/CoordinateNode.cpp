
#include "CoordinateNode.h"
#include <glm/gtx/transform.hpp>

void ore::scene::CoordinateNode::preRender(ore::RenderState &renderState) {
    // Create a backup copy of the current model matrix
    storedModelMatrix = renderState.transformations.model;

    // Compute and apply relative transformation matrix
    glm::mat4 relativeTransformation(1.0);
    relativeTransformation = glm::translate(relativeTransformation, position);
    relativeTransformation = glm::translate(relativeTransformation, pivot);
    relativeTransformation = glm::rotate(relativeTransformation, rotation.y, glm::vec3(0, 1, 0));
    relativeTransformation = glm::rotate(relativeTransformation, rotation.x, glm::vec3(1, 0, 0));
    relativeTransformation = glm::rotate(relativeTransformation, rotation.z, glm::vec3(0, 0, 1));
    relativeTransformation = glm::scale(relativeTransformation, scale);
    relativeTransformation = glm::translate(relativeTransformation, -pivot);

    renderState.transformations.model = relativeTransformation * renderState.transformations.model;
}

void ore::scene::CoordinateNode::postRender(ore::RenderState &renderState) {
    renderState.transformations.model = storedModelMatrix;
}

std::string ore::scene::CoordinateNode::getName() {
    return "Container node - " + name;
}
