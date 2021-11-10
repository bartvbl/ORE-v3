#include "LightNode.h"
#include <g3log/g3log.hpp>

void ore::LightNode::preRender(ore::RenderState &state) {
    for(unsigned int i = 0; i < lightSourceCount; i++) {
        
    }
}

void ore::LightNode::render(ore::RenderState &state) {
    preRender(state);

    ContainerNode::render(state);
}

void ore::LightNode::addLight(ore::gl::Light &light) {
    if(lightSourceCount >= ore::MAX_LIGHT_SOURCES) {
        LOG(FATAL) << "Attempted to add light, but this would exceed the maximum number of light sources supported!" << std::endl;
    }
    lightSources.at(lightSourceCount) = light;
    lightSourceCount++;
}

void ore::LightNode::clearLights() {
    lightSourceCount = 0;
}
