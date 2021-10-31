#include "MaterialNode.h"
#include <ore/gl/shader/ShaderUniformIndex.h>

void ore::scene::MaterialNode::render(ore::RenderState &state) {
    if(material->diffuseTexture.isLoaded()) {
        state.uniforms.setTexture(ore::gl::ShaderUniformIndex::diffuseTextureID, material->diffuseTexture.getInstance());
    }

    ContainerNode::render(state);
}
