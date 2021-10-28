#include <glad/glad.h>
#include "RenderPass.h"

void ore::RenderPass::render(ore::SceneNode *rootNode) {
    ore::RenderState state;
    rootNode->update(state);
    rootNode->render(state);
}