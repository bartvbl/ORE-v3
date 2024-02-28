#include "MaterialNode.h"
#include <ore/gl/shader/ShaderUniformIndex.h>

void ore::scene::MaterialNode::render(ore::RenderState &state) {
    ore::gl::ShadingConfiguration oldConfig = state.shading;

    if(material->hasDiffuseTexture() && state.shading.enableTexturing) {
        state.uniforms.setTexture(ore::gl::ShaderUniformIndex::diffuseTextureID, material->diffuseTexture);
    } else {
        state.shading.enableTexturing = false;
    }
    if(material->hasNormalMap() && state.shading.enableNormalMapping) {
        state.uniforms.setTexture(ore::gl::ShaderUniformIndex::normalMapTextureID, material->normalMapTexture);
    } else {
        state.shading.enableNormalMapping = false;
    }

    state.uniforms.setDiffuseColour(ore::gl::ShaderUniformIndex::materialColourDiffuse, glm::vec4(material->diffuseColour.x, material->diffuseColour.y, material->diffuseColour.z, material->diffuseColour.w));

    ContainerNode::render(state);

    state.shading = oldConfig;
}
