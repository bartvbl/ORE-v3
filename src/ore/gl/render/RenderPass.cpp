#include <glad/glad.h>
#include "RenderPass.h"

void ore::RenderPass::render(ore::SceneNode *rootNode) {
    ore::RenderState state;
    rootNode->preUpdate(state);
    rootNode->preRender(state);
    rootNode->render(state);
    rootNode->postRender(state);
    rootNode->postUpdate(state);
}