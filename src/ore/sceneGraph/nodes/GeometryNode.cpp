#include <glad/glad.h>
#include "GeometryNode.h"
#include <glm/gtc/type_ptr.hpp>

void ore::scene::GeometryNode::preRender(ore::RenderState &renderState) {

}

void ore::scene::GeometryNode::render(ore::RenderState &renderState) {
    glm::mat4 mvpMatrix = renderState.transformations.projection * renderState.transformations.perspectiveView * modelMatrix;
    glUniformMatrix4fv(6, 1, GL_FALSE, glm::value_ptr(mvpMatrix));
    glBindVertexArray(buffer.vaoID);
    glDrawElements(GL_TRIANGLES, buffer.indexCount, GL_UNSIGNED_INT, nullptr);
}

void ore::scene::GeometryNode::postRender(ore::RenderState &renderState) {

}

void ore::scene::GeometryNode::preUpdate(ore::RenderState &renderState) {
    CoordinateNode::preUpdate(renderState);
    modelMatrix = renderState.transformations.model;
}

void ore::scene::GeometryNode::postUpdate(ore::RenderState &renderState) {
    CoordinateNode::postUpdate(renderState);
}
