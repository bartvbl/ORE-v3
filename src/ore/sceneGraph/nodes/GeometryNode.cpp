#include <glad/glad.h>
#include "GeometryNode.h"
#include <glm/gtc/type_ptr.hpp>
#include <ore/gl/shader/ShaderUniformIndex.h>
#include <ore/gl/render/RenderMode.h>
#include <array>

void ore::scene::GeometryNode::preRender(ore::RenderState &state) {
    CoordinateNode::preRender(state);

    glm::mat4 mvMatrix = state.transformations.view * state.transformations.model;
    glm::mat4 mvpMatrix = state.transformations.projection * mvMatrix;
    glm::mat4x4 normalMatrix = glm::transpose(glm::inverse(mvMatrix));
    std::array<glm::mat4, ore::MAX_SHADOW_LIGHT_SOURCES> shadowMVPs;
    for(unsigned int i = 0; i < ore::MAX_SHADOW_LIGHT_SOURCES; i++) {
        shadowMVPs.at(i) = state.transformations.shadowVP.at(i) * state.transformations.model;
    }

    glUniform1i(ore::gl::ShaderUniformIndex::diffuseTextureEnabled, state.shading.enableTexturing ? 1 : 0);
    glUniform1i(ore::gl::ShaderUniformIndex::lightingEnabled, state.shading.enableLighting ? 1 : 0);
    glUniform1i(ore::gl::ShaderUniformIndex::shadowsEnabled, state.shading.enableShadows ? 1 : 0);
    glUniform1i(ore::gl::ShaderUniformIndex::normalMappingEnabled, state.shading.enableNormalMapping ? 1 : 0);

    glUniformMatrix4fv(ore::gl::ShaderUniformIndex::modelViewProjectionMatrix, 1, GL_FALSE, glm::value_ptr(mvpMatrix));
    glUniformMatrix4fv(ore::gl::ShaderUniformIndex::modelViewMatrix, 1, GL_FALSE, glm::value_ptr(mvMatrix));
    glUniformMatrix4fv(ore::gl::ShaderUniformIndex::normalMatrix, 1, GL_FALSE, glm::value_ptr(normalMatrix));
    glUniformMatrix4fv(ore::gl::ShaderUniformIndex::shadowMapMVP, 4, GL_FALSE, glm::value_ptr(shadowMVPs.at(0)));
}

void ore::scene::GeometryNode::render(ore::RenderState &renderState) {
    this->preRender(renderState);

    bool isTransparentObjectInShadowPass = renderState.shading.isShadowDepthPass && renderState.uniforms.diffuseColour.a < 1.0;

    if(!isTransparentObjectInShadowPass) {
        drawBuffer();
    }


    CoordinateNode::render(renderState);
    CoordinateNode::postRender(renderState);
}

void ore::scene::GeometryNode::destroyGeometryBuffer() {
    buffer.destroy();
}

void ore::scene::GeometryNode::setRenderMode(ore::gl::RenderMode mode) {
    this->mode = mode;
}

void ore::scene::GeometryNode::drawBuffer() const {
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
}


