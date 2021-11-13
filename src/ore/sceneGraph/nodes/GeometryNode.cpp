#include <glad/glad.h>
#include "GeometryNode.h"
#include <glm/gtc/type_ptr.hpp>
#include <ore/gl/shader/ShaderUniformIndex.h>
#include <ore/gl/render/RenderMode.h>

void ore::scene::GeometryNode::render(ore::RenderState &renderState) {
    CoordinateNode::preRender(renderState);

    glm::mat4 mvMatrix = renderState.transformations.view * renderState.transformations.model;
    glm::mat4 mvpMatrix = renderState.transformations.projection * mvMatrix;
    glm::mat4x4 normalMatrix = glm::transpose(glm::inverse(mvMatrix));

    glUniformMatrix4fv(ore::gl::ShaderUniformIndex::modelViewProjectionMatrix, 1, GL_FALSE, glm::value_ptr(mvpMatrix));
    glUniformMatrix4fv(ore::gl::ShaderUniformIndex::modelViewMatrix, 1, GL_FALSE, glm::value_ptr(mvMatrix));
    glUniformMatrix4fv(ore::gl::ShaderUniformIndex::normalMatrix, 1, GL_FALSE, glm::value_ptr(normalMatrix));
    glUniformMatrix4fv(ore::gl::ShaderUniformIndex::shadowMapMVP, 1, GL_FALSE, glm::value_ptr(renderState.transformations.shadowMVP));

    glBindVertexArray(buffer.vaoID);
    const unsigned int* zeroptr = nullptr;
    unsigned int drawMode = 0;
    switch(mode) {
        case gl::RenderMode::TRIANGLES:
            drawMode = GL_TRIANGLES;
            break;
        case gl::RenderMode::LINES:
            drawMode = GL_LINES;
            break;
    }
    glDrawElements(drawMode, indexCount, GL_UNSIGNED_INT, (void*) (zeroptr + startIndex));

    CoordinateNode::render(renderState);
    CoordinateNode::postRender(renderState);
}

void ore::scene::GeometryNode::destroyGeometryBuffer() {
    buffer.destroy();
}

void ore::scene::GeometryNode::setRenderMode(ore::gl::RenderMode mode) {
    this->mode = mode;
}
