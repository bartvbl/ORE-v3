#include "ShaderNode.h"

void ore::scene::ShaderNode::render(ore::RenderState &renderState) {
    if(isShaderSet) {
        shader.use();
        renderState.currentActiveShader = shader;
    }

    SceneNode::render(renderState);
}
