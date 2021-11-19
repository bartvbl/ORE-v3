#include "MeshNode.h"

std::string ore::MeshNode::getName() {
    return "Mesh Node - " + name;
}

void ore::MeshNode::destroy() {

}

void ore::MeshNode::render(ore::RenderState &state) {
    ore::scene::CoordinateNode::preRender(state);
    ore::gl::ShadingConfiguration oldConfig = state.shading;
    state.shading = this->shading;
    state.shading.isShadowDepthPass = oldConfig.isShadowDepthPass;
    ore::scene::CoordinateNode::render(state);
    state.shading = oldConfig;
    ore::scene::CoordinateNode::postRender(state);
}

