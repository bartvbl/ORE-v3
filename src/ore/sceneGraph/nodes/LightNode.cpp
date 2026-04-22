#include "LightNode.h"

#include <iostream>
#include <g3log/g3log.hpp>
#include <ore/gl/shader/ShaderUniformIndex.h>
#include <glad/glad.h>

#include "glm/gtx/string_cast.hpp"
#include "ore/gl/camera/TripodCameraTransform.h"


void ore::scene::LightNode::preRender(ore::RenderState &state) {
    glm::mat4 modelViewMatrix = state.transformations.view * state.transformations.model;
    glm::mat4x4 normalMatrix = glm::transpose(glm::inverse(modelViewMatrix));
    std::array<glm::vec3, ore::MAX_LIGHT_SOURCES> transformedLightPositions{};
    std::array<float, ore::MAX_LIGHT_SOURCES> lightAttenuations{};
    std::array<glm::vec3, ore::MAX_LIGHT_SOURCES> lightColours{};
    std::array<glm::vec3, ore::MAX_LIGHT_SOURCES> transformedLightDirections{};
    std::array<float, ore::MAX_LIGHT_SOURCES> spotLightAngles{};
    std::array<uint32_t, ore::MAX_LIGHT_SOURCES> lightParametersFlags{};

    for(unsigned int i = 0; i < lightSourceCount; i++) {
        transformedLightPositions.at(i) = modelViewMatrix * glm::vec4(lightSources.at(i).position, 1.0);
        lightAttenuations.at(i) = lightSources.at(i).attenuation;
        lightColours.at(i) = lightSources.at(i).lightColour;
        glm::mat4 identityMatrix = glm::mat4(1);
        glm::mat4 directionMatrix = ore::gl::computeTripodViewTransformation(identityMatrix, glm::vec3(0, 0, 0), lightSources.at(i).lightDirection);
        glm::vec4 direction = directionMatrix * glm::vec4(0.0, 0.0, 1.0, 1.0);

        transformedLightDirections.at(i) = glm::normalize(glm::vec3(normalMatrix * direction));
        spotLightAngles.at(i) = glm::radians(lightSources.at(i).spotLightAngleDegrees);
        lightParametersFlags.at(i) =
                  ore::gl::LightSourceParameter::enabledBit
                | (lightSources.at(i).type == ore::gl::LightType::SPOT_LIGHT ? ore::gl::LightSourceParameter::isSpotLightBit : 0)
                | (lightSources.at(i).enableLightOutsideShadowMap ? ore::gl::LightSourceParameter::shadowSource_enableOutsideShadowBit : 0)
                | (lightSources.at(i).showLightBeams ? ore::gl::LightSourceParameter::spotLight_showLightBeamBit : 0);
    }
    state.uniforms.setLightPositions(ore::gl::ShaderUniformIndex::lightPositionArrayID,
                                     ore::gl::ShaderUniformIndex::lightPositionArrayCount,
                                     reinterpret_cast<GLfloat*>(transformedLightPositions.data()),
                                     lightSourceCount);

    glUniform3fv(ore::gl::ShaderUniformIndex::lightSpotLightDirectionArray, static_cast<int>(lightSourceCount), reinterpret_cast<GLfloat*>(transformedLightDirections.data()));
    glUniform1fv(ore::gl::ShaderUniformIndex::lightSpotLightAngleArray, static_cast<int>(lightSourceCount), reinterpret_cast<GLfloat*>(spotLightAngles.data()));
    glUniform3fv(ore::gl::ShaderUniformIndex::lightColourArray, static_cast<int>(lightSourceCount), reinterpret_cast<GLfloat*>(lightColours.data()));
    glUniform1uiv(ore::gl::ShaderUniformIndex::lightParameterflagArray, static_cast<int>(lightSourceCount), lightParametersFlags.data());
    glUniform1fv(ore::gl::ShaderUniformIndex::lightAttenuationArray, static_cast<int>(lightSourceCount), lightAttenuations.data());


}

void ore::scene::LightNode::render(ore::RenderState &state) {
    preRender(state);

    ContainerNode::render(state);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    ore::resources::Shader oldShader = state.currentActiveShader;
    state.currentActiveShader = lightBeamShader;
    lightBeamShader.use();
    for(unsigned int i = 0; i < lightSourceCount; i++) {
        if (lightSources.at(i).type == ore::gl::LightType::SPOT_LIGHT && lightSources.at(i).showLightBeams) {
            this->lightConeLocationNode.position = lightSources.at(i).position;
            this->lightConeLocationNode.rotation = lightSources.at(i).lightDirection;
            float spotlightSine = std::sin(glm::radians(lightSources.at(i).spotLightAngleDegrees));
            this->lightConeLocationNode.scale = glm::vec3(100.0 * spotlightSine, 100.0 * spotlightSine, 100.0);
            this->lightConeLocationNode.preRender(state);
            this->lightConeLocationNode.render(state);
            this->lightConeLocationNode.postRender(state);
        }
    }
    state.currentActiveShader = oldShader;
    oldShader.use();
}

void ore::scene::LightNode::postRender(ore::RenderState &state) {
    ContainerNode::postRender(state);
}

void ore::scene::LightNode::addLight(ore::gl::Light &light) {
    if(lightSourceCount >= ore::MAX_LIGHT_SOURCES) {
        LOG(FATAL) << "Attempted to add light, but this would exceed the maximum number of light sources supported!" << std::endl;
    }
    lightSources.at(lightSourceCount) = light;
    lightSourceCount++;
}

void ore::scene::LightNode::clearLights() {
    lightSourceCount = 0;
}
