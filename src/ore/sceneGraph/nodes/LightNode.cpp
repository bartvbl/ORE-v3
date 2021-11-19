#include "LightNode.h"
#include <g3log/g3log.hpp>
#include <ore/gl/shader/ShaderUniformIndex.h>
#include <glad/glad.h>

void ore::scene::LightNode::preRender(ore::RenderState &state) {
    glm::mat4 modelViewMatrix = state.transformations.view * state.transformations.model;
    std::array<glm::vec3, ore::MAX_LIGHT_SOURCES> transformedLightPositions;
    for(unsigned int i = 0; i < lightSourceCount; i++) {
        transformedLightPositions.at(i) = modelViewMatrix * glm::vec4(lightSources.at(i).position, 1.0);
    }
    state.uniforms.setLightPositions(ore::gl::ShaderUniformIndex::lightPositionArrayID,
                                     ore::gl::ShaderUniformIndex::lightPositionArrayCount,
                                     reinterpret_cast<GLfloat*>(transformedLightPositions.data()),
                                     lightSourceCount);
}

void ore::scene::LightNode::render(ore::RenderState &state) {
    preRender(state);

    ContainerNode::render(state);
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
