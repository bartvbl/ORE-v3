#include <ore/resources/resourceTypes/texture/Texture.h>
#include <glad/glad.h>
#include "RenderState.h"
#include <ore/gl/shader/ShaderUniformIndex.h>

void ore::ShaderUniformRenderState::setTexture(unsigned int ID, ore::resources::Texture texture) {
    glBindTextureUnit(ID, texture.id);
    glUniform1i(ore::gl::ShaderUniformIndex::diffuseTextureEnabled, 1);
}

void ore::ShaderUniformRenderState::setLightPositions(const unsigned int baseUniformID, float* positionList, unsigned int count) {
    glUniform3fv(baseUniformID, count, positionList);
    glUniform1i(ore::gl::ShaderUniformIndex::lightPositionArrayCount, count);
}
