#include "MaterialNode.h"
#include <ore/gl/shader/ShaderUniformIndex.h>

void ore::scene::MaterialNode::render(ore::RenderState &state) {
    if(material->hasDiffuseTexture() && state.shading.enableTexturing) {
        state.uniforms.setTexture(ore::gl::ShaderUniformIndex::diffuseTextureID, material->diffuseTexture);
    }

    state.uniforms.setColour(ore::gl::ShaderUniformIndex::materialColourDiffuse, material->diffuseColour);

    ContainerNode::render(state);
}
