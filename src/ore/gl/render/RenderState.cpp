#include <ore/resources/resourceTypes/texture/Texture.h>
#include <glad/glad.h>
#include "RenderState.h"

void ore::ShaderUniformRenderState::setTexture(unsigned int ID, ore::resources::Texture texture) {
    glBindTextureUnit(ID, texture.id);
}
