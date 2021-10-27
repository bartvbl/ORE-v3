#include "SceneNode.h"

void ore::SceneNode::update(ore::RenderState &renderState) {
    for(SceneNode* node : *getChildren()) {
        node->update(renderState);
    }
}

void ore::SceneNode::preRender(ore::RenderState &renderState) {}

void ore::SceneNode::render(ore::RenderState &renderState) {
    for(SceneNode* node : *getChildren()) {
        node->update(renderState);
    }
}

void ore::SceneNode::postRender(ore::RenderState &renderState) {}

void ore::SceneNode::destroy() {}


