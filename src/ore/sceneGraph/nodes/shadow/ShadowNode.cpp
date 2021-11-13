#include <glad/glad.h>
#include "ShadowNode.h"
#include <ore/gl/shader/ShaderUniformIndex.h>
#include <ore/gl/camera/TripodCameraTransform.h>

std::vector<ore::SceneNode*> *ore::scene::ShadowNode::getChildren() {
    return shadowedSceneContentsNode.getChildren();
}

void ore::scene::ShadowNode::setLightSource(ore::gl::Light lightSource) {
    this->lightSource = lightSource;
}

void ore::scene::ShadowNode::render(ore::RenderState &state) {
    // Move camera to light source view point
    glm::mat4 previousViewMatrix = state.transformations.view;
    glm::mat4 positionTransformation = ore::gl::computeTripodViewTransformation(lightSource.position, lightSource.lightDirection);
    state.transformations.view = positionTransformation;

    // Depth pass
    glBindFramebuffer(GL_FRAMEBUFFER, frameBuffer.id);
    glViewport(0, 0, SHADOW_MAP_WIDTH, SHADOW_MAP_HEIGHT);
    glClear(GL_DEPTH_BUFFER_BIT);
    depthPassShaderNode.render(state);

    // Restore original camera position
    state.transformations.view = previousViewMatrix;

    // Shadow pass
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    glViewport(0, 0, state.window.width, state.window.height);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    state.uniforms.setTexture(ore::gl::ShaderUniformIndex::shadowDepthMapTextureID, texture.id);
    shadowShaderNode.render(state);


}
