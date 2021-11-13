#include "SceneGraphPrinter.h"
#include <iostream>

void walk(ore::SceneNode* node, unsigned level = 0) {
    for(unsigned int i = 0; i < level; i++) {
        std::cout << "  ";
    }
    std::cout << node->getName() << std::endl;

    for(ore::SceneNode* childNode : *node->getChildren()) {
        walk(childNode, level + 1);
    }
}

void ore::utilities::printSceneGraph(ore::SceneNode *node) {
    walk(node);
}
