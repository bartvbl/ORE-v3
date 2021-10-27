#include "ContainerNode.h"


std::vector<ore::SceneNode*>* ore::scene::ContainerNode::getChildren() {
    return &childVector;
}

void ore::scene::ContainerNode::destroy() {

}

std::string ore::scene::ContainerNode::getName() {
    return name;
}
