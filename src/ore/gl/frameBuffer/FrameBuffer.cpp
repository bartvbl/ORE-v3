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
    this->depthTexture = tex;
}

void ore::gl::FrameBuffer::makeOffscreenRenderFrameBuffer(ore::resources::Texture tex) {
    glBindFramebuffer(GL_FRAMEBUFFER, id);
    glViewport(0, 0, tex.widthPixels, tex.heightPixels);
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
   /* this->texture = tex;


    glBindFramebuffer(GL_FRAMEBUFFER, id);

    glGenTextures(1, &renderTextureID);
    glBindTexture(GL_TEXTURE_2D, renderTextureID);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, offscreenTextureWidth, offscreenTextureHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, renderTextureID, 0);

    glGenTextures(1, &depthTextureID);
    glBindTexture(GL_TEXTURE_2D, depthTextureID);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, offscreenTextureWidth, offscreenTextureHeight, 0, GL_DEPTH_COMPONENT, GL_FLOAT, 0);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_FUNC, GL_LEQUAL);
    glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_COMPARE_MODE, GL_NONE);

    glGenRenderbuffers(1, &renderBufferID);
    glBindRenderbuffer(GL_RENDERBUFFER, renderBufferID);
    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, offscreenTextureWidth, offscreenTextureHeight);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, renderBufferID);*/
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
