
#include "CoordinateNode.h"
#include <glm/gtx/transform.hpp>

std::string ore::scene::CoordinateNode::getName() {
    return "Coordinate node - " + name;
}

void ore::scene::CoordinateNode::preRender(ore::RenderState &renderState) {
    // Create a backup copy of the current model matrix
    storedModelMatrix = renderState.transformations.model;

    // Compute and apply relative transformation matrix
    glm::mat4 relativeTransformation(1.0);
    relativeTransformation *= glm::translate(glm::mat4(1.0), position);
    relativeTransformation *= glm::translate(glm::mat4(1.0), pivot);
    relativeTransformation *= glm::rotate(glm::mat4(1.0), glm::radians(rotation.x), glm::vec3(1, 0, 0));
    relativeTransformation *= glm::rotate(glm::mat4(1.0), glm::radians(rotation.y), glm::vec3(0, 1, 0));
    relativeTransformation *= glm::rotate(glm::mat4(1.0), glm::radians(rotation.z), glm::vec3(0, 0, 1));
    relativeTransformation *= glm::scale(glm::mat4(1.0), scale);
    relativeTransformation *= glm::translate(glm::mat4(1.0), -pivot);

    renderState.transformations.model = relativeTransformation * renderState.transformations.model;
}

void ore::scene::CoordinateNode::render(ore::RenderState &renderState) {
    ContainerNode::render(renderState);
}

void ore::scene::CoordinateNode::postRender(ore::RenderState &renderState) {
    renderState.transformations.model = storedModelMatrix;
}
