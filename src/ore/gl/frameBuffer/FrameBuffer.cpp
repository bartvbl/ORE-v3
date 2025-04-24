#include <glad/glad.h>
#include <ore/gl/render/RenderState.h>
#include "FrameBuffer.h"

void ore::gl::FrameBuffer::create() {
    glGenFramebuffers(1, &id);
}

void ore::gl::FrameBuffer::makeShadowMapFramebuffer(ore::resources::ShadowTexture tex) {
    glBindFramebuffer(GL_FRAMEBUFFER, id);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, tex.id, 0);
    glDrawBuffer(GL_NONE);
    glReadBuffer(GL_NONE);
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void ore::gl::FrameBuffer::activate() {
    glBindFramebuffer(GL_FRAMEBUFFER, id);
   // glViewport(0, 0, texture.widthPixels, texture.heightPixels);
    glClear(GL_DEPTH_BUFFER_BIT);
}

void ore::gl::FrameBuffer::deactivate(const WindowDimensionsRenderState windowState) {
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    glViewport(0, 0, windowState.width, windowState.height);
}
