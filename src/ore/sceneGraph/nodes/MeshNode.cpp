#include "MeshNode.h"

std::string ore::MeshNode::getName() {
    return "Mesh Node - " + name;
}

void ore::MeshNode::destroy() {

}

void ore::MeshNode::render(ore::RenderState &state) {
    ore::scene::CoordinateNode::preRender(state);
    ore::scene::CoordinateNode::render(state);
    ore::scene::CoordinateNode::postRender(state);
}

