#include <ore/resources/resourceTypes/texture/Texture.h>
#include <glad/glad.h>
#include "RenderState.h"
#include <ore/gl/shader/ShaderUniformIndex.h>

void ore::ShaderUniformRenderState::setTexture(unsigned int ID, ore::resources::Texture texture) {
    glBindTextureUnit(ID, texture.id);
    glUniform1i(ore::gl::ShaderUniformIndex::diffuseTextureEnabled, 1);
}

void ore::ShaderUniformRenderState::setLightPositions(const unsigned int baseUniformID, const unsigned int arrayLengthUniformID, float* positionList, unsigned int count) {
    glUniform3fv(baseUniformID, count, positionList);
    glUniform1i(arrayLengthUniformID, count);
}

void ore::ShaderUniformRenderState::setDiffuseColour(const unsigned int uniformID, glm::vec4 colour) {
    glUniform4f(uniformID, colour.x, colour.y, colour.z, colour.w);
    diffuseColour = colour;
}

void ore::ShaderUniformRenderState::setInteger(const unsigned int uniformID, unsigned int value) {
    glUniform1i(uniformID, value);
}
