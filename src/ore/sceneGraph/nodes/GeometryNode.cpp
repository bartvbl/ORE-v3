#include <glad/glad.h>
#include "GeometryNode.h"
#include <glm/gtc/type_ptr.hpp>
#include <ore/gl/shader/ShaderUniformIndex.h>

void ore::scene::GeometryNode::render(ore::RenderState &renderState) {
    CoordinateNode::preRender(renderState);
    glm::mat4 mvpMatrix = renderState.transformations.projection * renderState.transformations.view * renderState.transformations.model;
    glUniformMatrix4fv(ore::gl::ShaderUniformIndex::modelViewProjectionMatrix, 1, GL_FALSE, glm::value_ptr(mvpMatrix));
    glBindVertexArray(buffer.vaoID);
    const unsigned int* zeroptr = nullptr;
    glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, (void*) (zeroptr + startIndex));

    CoordinateNode::render(renderState);
    CoordinateNode::postRender(renderState);
}

void ore::scene::GeometryNode::destroyGeometryBuffer() {
    buffer.destroy();
}
