#include "ContainerNode.h"

void ore::scene::ContainerNode::preRender(ore::RenderState &renderState) {
    // Do nothing
}

void ore::scene::ContainerNode::render(ore::RenderState &renderState) {
    // Do nothing
}

void ore::scene::ContainerNode::postRender(ore::RenderState &renderState) {
    // Do nothing
}


std::vector<ore::SceneNode*>* ore::scene::ContainerNode::getChildren() {
    return &childVector;
}

void ore::scene::ContainerNode::destroy() {

}

std::string ore::scene::ContainerNode::getName() {
    return name;
}

void ore::scene::ContainerNode::preUpdate(ore::RenderState &renderState) {
    // Do nothing
}

void ore::scene::ContainerNode::postUpdate(ore::RenderState &renderState) {
    // Do nothing
}
