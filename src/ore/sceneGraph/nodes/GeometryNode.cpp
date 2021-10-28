#include <glad/glad.h>
#include "GeometryNode.h"
#include <glm/gtc/type_ptr.hpp>

void ore::scene::GeometryNode::render(ore::RenderState &renderState) {
    CoordinateNode::preRender(renderState);
    glm::mat4 mvpMatrix = renderState.transformations.projection * renderState.transformations.view * renderState.transformations.model;
    glUniformMatrix4fv(6, 1, GL_FALSE, glm::value_ptr(mvpMatrix));
    glBindVertexArray(buffer.vaoID);
    glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, nullptr);

    CoordinateNode::render(renderState);

    CoordinateNode::postRender(renderState);
}
