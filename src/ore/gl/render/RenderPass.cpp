#include <glad/glad.h>
#include "RenderPass.h"

void doRenderPassUpdate(ore::SceneNode* node, ore::RenderState &renderState) {
    node->preUpdate(renderState);
    for(ore::SceneNode* childNode : *node->getChildren()) {
        doRenderPassUpdate(childNode, renderState);
    }
    node->postUpdate(renderState);
}

void doRenderPassRender(ore::SceneNode* node, ore::RenderState &renderState) {
    node->preRender(renderState);
    node->render(renderState);
    for(ore::SceneNode* childNode : *node->getChildren()) {
        doRenderPassRender(childNode, renderState);
    }
    node->postRender(renderState);
}

void ore::RenderPass::render(ore::SceneNode *rootNode) {
    ore::RenderState state;
    doRenderPassUpdate(rootNode, state);
    doRenderPassRender(rootNode, state);
}