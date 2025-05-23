#include <glad/glad.h>
#include "ShadowNode.h"
#include <ore/gl/shader/ShaderUniformIndex.h>
#include <ore/gl/camera/TripodCameraTransform.h>
#include <glm/gtc/matrix_transform.hpp>

std::vector<ore::SceneNode*> *ore::scene::ShadowNode::getChildren() {
    return shadowedSceneContentsNode.getChildren();
}

void ore::scene::ShadowNode::render(ore::RenderState &state) {
    // Move camera to light source view point
    glm::mat4 previousViewMatrix = state.transformations.view;
    glm::mat4 previousProjectionMatrix = state.transformations.projection;

    for(unsigned int lightSourceIndex = 0; lightSourceIndex < lightSourceCount; lightSourceIndex++) {
        state.transformations.view = ore::gl::computeTripodViewTransformation(state.transformations.model,
                                                                              -lightSources.at(
                                                                                      lightSourceIndex).position,
                                                                              lightSources.at(
                                                                                      lightSourceIndex).lightDirection);
        if(lightSources.at(lightSourceIndex).type == ore::gl::LightType::SPOT_LIGHT) {
            state.transformations.projection = glm::perspective(
                    glm::radians(lightSources.at(lightSourceIndex).spotLightAngleDegrees),
                    float(SHADOW_MAP_WIDTH) / float(SHADOW_MAP_HEIGHT), 0.001f,
                    1000.0f);
        } else {
            float radius = lightSources.at(lightSourceIndex).directionalLightRadius;
            state.transformations.projection = glm::ortho(
                    -radius, radius, -radius, radius, 0.1f,
                    10.0f);
        }


        // Depth pass
        state.shading.isShadowDepthPass = true;
        glBindFramebuffer(GL_FRAMEBUFFER, frameBuffers.at(lightSourceIndex).id);
        glViewport(0, 0, SHADOW_MAP_WIDTH, SHADOW_MAP_HEIGHT);
        glClear(GL_DEPTH_BUFFER_BIT);
        depthPassShaderNode.render(state);
        state.shading.isShadowDepthPass = false;

        state.transformations.shadowVP.at(lightSourceIndex) = state.transformations.projection * state.transformations.view;
    }

    // Swap to the main shadow render shader
    shadowShaderNode.render(state);

    // Restore original camera position
    state.transformations.view = previousViewMatrix;
    state.transformations.projection = previousProjectionMatrix;

    // Shadow pass
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    glViewport(0, 0, state.window.width, state.window.height);
    switch(lightSourceCount) {
        case 4:
            state.uniforms.setTexture(ore::gl::ShaderUniformIndex::shadowDepthMapTextureID3, textures.at(3));
        case 3:
            state.uniforms.setTexture(ore::gl::ShaderUniformIndex::shadowDepthMapTextureID2, textures.at(2));
        case 2:
            state.uniforms.setTexture(ore::gl::ShaderUniformIndex::shadowDepthMapTextureID1, textures.at(1));
        case 1:
            state.uniforms.setTexture(ore::gl::ShaderUniformIndex::shadowDepthMapTextureID0, textures.at(0));
    }

    if(lightSourceCount != 0) {
        state.shading.enableShadows = true;
    } else {
        state.shading.enableShadows = false;
    }

    glm::mat4 modelViewMatrix = state.transformations.view * state.transformations.model;
    std::array<glm::vec3, ore::MAX_SHADOW_LIGHT_SOURCES> transformedLightPositions;
    std::array<float, ore::MAX_SHADOW_LIGHT_SOURCES> lightAttenuations;
    for(unsigned int i = 0; i < lightSourceCount; i++) {
        transformedLightPositions.at(i) = modelViewMatrix * glm::vec4(lightSources.at(i).position, 1.0);
        lightAttenuations.at(i) = lightSources.at(i).attenuation;
    }
    state.uniforms.setLightPositions(ore::gl::ShaderUniformIndex::shadowLightPositionArray,
                                     ore::gl::ShaderUniformIndex::shadowLightCount,
                                     reinterpret_cast<GLfloat*>(transformedLightPositions.data()),
                                     lightSourceCount);
    glUniform1fv(ore::gl::ShaderUniformIndex::shadowLightAttenuationArray, lightSourceCount, lightAttenuations.data());


    shadowedSceneContentsNode.render(state);

}

void ore::scene::ShadowNode::addLight(ore::gl::Light &light) {
    if(lightSourceCount >= ore::MAX_SHADOW_LIGHT_SOURCES) {
        LOG(FATAL) << "Tried to add too many shadow light sources!" << std::endl;
    }
    if(light.type != ore::gl::LightType::DIRECTIONAL_LIGHT && light.type != ore::gl::LightType::SPOT_LIGHT) {
        LOG(FATAL) << "Shadow light sources must be of type 'directionalLight' or 'spotLight'." << std::endl;
    }
    lightSources.at(lightSourceCount) = light;
    lightSourceCount++;
}

void ore::scene::ShadowNode::clearLights() {
    lightSourceCount = 0;
}
