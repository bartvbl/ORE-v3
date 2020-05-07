#include "ContainerNode.h"

void ore::ContainerNode::preRender(ore::RenderState &renderState) {
    // Do nothing
}

void ore::ContainerNode::render(ore::RenderState &renderState) {
    // Do nothing
}

void ore::ContainerNode::postRender(ore::RenderState &renderState) {
    // Do nothing
}

std::vector<ore::SceneNode> *ore::ContainerNode::getChildren() {
    return &childVector;
}

void ore::ContainerNode::destroy() {

}

std::string ore::ContainerNode::getName() {
    return name;
}
