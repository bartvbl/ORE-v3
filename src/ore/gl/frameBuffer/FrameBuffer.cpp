#include <glad/glad.h>
#include "FrameBuffer.h"

void ore::gl::FrameBuffer::create() {
    glGenFramebuffers(1, &id);
}

void ore::gl::FrameBuffer::makeShadowMapFramebuffer(ore::resources::ShadowTexture texture) const {
    glBindFramebuffer(GL_FRAMEBUFFER, id);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, texture.id, 0);
    glDrawBuffer(GL_NONE);
    glReadBuffer(GL_NONE);
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}
