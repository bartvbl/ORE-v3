#include <glad/glad.h>
#include "ShadowNode.h"
#include <ore/gl/shader/ShaderUniformIndex.h>
#include <ore/gl/camera/TripodCameraTransform.h>
#include <glm/gtc/matrix_transform.hpp>
#include <cmath>

std::vector<ore::SceneNode*> *ore::scene::ShadowNode::getChildren() {
    return shadowedSceneContentsNode.getChildren();
}

void ore::scene::ShadowNode::setLightSource(ore::gl::Light updatedLightSource) {
    this->lightSource = updatedLightSource;
}

void ore::scene::ShadowNode::render(ore::RenderState &state) {
    // Move camera to light source view point
    glm::mat4 previousViewMatrix = state.transformations.view;
    glm::mat4 previousProjectionMatrix = state.transformations.projection;

    state.transformations.view = ore::gl::computeTripodViewTransformation(state.transformations.model, -lightSource.position, lightSource.lightDirection);
    state.transformations.projection = glm::perspective(glm::radians(lightSource.spotLightAngleDegrees), float(SHADOW_MAP_WIDTH) / float(SHADOW_MAP_HEIGHT), 0.1f, 1000.0f);

    // Depth pass
    glBindFramebuffer(GL_FRAMEBUFFER, frameBuffer.id);
    glViewport(0, 0, SHADOW_MAP_WIDTH, SHADOW_MAP_HEIGHT);
    glClear(GL_DEPTH_BUFFER_BIT);
    depthPassShaderNode.render(state);

    // Restore original camera position
    state.transformations.shadowVP = state.transformations.projection * state.transformations.view;
    state.transformations.view = previousViewMatrix;
    state.transformations.projection = previousProjectionMatrix;

    // Shadow pass
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    glViewport(0, 0, state.window.width, state.window.height);
    state.uniforms.setTexture(ore::gl::ShaderUniformIndex::shadowDepthMapTextureID, texture.id);
    shadowShaderNode.render(state);


}
