#include "MaterialNode.h"
#include <ore/gl/shader/ShaderUniformIndex.h>

void ore::scene::MaterialNode::render(ore::RenderState &state) {
    if(material->hasDiffuseTexture() && state.shading.enableTexturing) {
        state.uniforms.setTexture(ore::gl::ShaderUniformIndex::diffuseTextureID, material->diffuseTexture);
    } else {
        state.shading.enableTexturing = false;
    }

    state.uniforms.setDiffuseColour(ore::gl::ShaderUniformIndex::materialColourDiffuse, glm::vec4(material->diffuseColour.x, material->diffuseColour.y, material->diffuseColour.z, material->diffuseColour.w));

    ContainerNode::render(state);
}
