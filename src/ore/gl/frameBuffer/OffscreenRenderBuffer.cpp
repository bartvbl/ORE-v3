#include <glad/glad.h>
#include <ore/gl/render/RenderState.h>
#include <stdexcept>
#include "OffscreenRenderBuffer.h"

void ore::gl::OffscreenRenderBuffer::create(int32_t widthPixels, int32_t heightPixels) {
    glGenFramebuffers(1, &id);

    glBindFramebuffer(GL_FRAMEBUFFER, id);
    glViewport(0, 0, widthPixels, heightPixels);
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);

    glBindFramebuffer(GL_FRAMEBUFFER, id);

    glGenTextures(1, &colourTexture.id);
    glBindTexture(GL_TEXTURE_2D, colourTexture.id);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, widthPixels, heightPixels, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, colourTexture.id, 0);

    glGenTextures(1, &depthTexture.id);
    glBindTexture(GL_TEXTURE_2D, depthTexture.id);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, widthPixels, heightPixels, 0, GL_DEPTH_COMPONENT, GL_FLOAT, 0);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_FUNC, GL_LEQUAL);
    glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_COMPARE_MODE, GL_NONE);

    glGenRenderbuffers(1, &renderBufferID);
    glBindRenderbuffer(GL_RENDERBUFFER, renderBufferID);
    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, widthPixels, heightPixels);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, renderBufferID);

    if(glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) {
        throw std::runtime_error("Framebuffer creation failed!");
    }
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void ore::gl::OffscreenRenderBuffer::activate(bool clear) {
    glBindFramebuffer(GL_FRAMEBUFFER, id);
    if(clear) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }
}

void ore::gl::OffscreenRenderBuffer::deactivate() {
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    //glViewport(0, 0, windowState.width, windowState.height);
}

void ore::gl::OffscreenRenderBuffer::render(ore::RenderState &renderState) {

}
