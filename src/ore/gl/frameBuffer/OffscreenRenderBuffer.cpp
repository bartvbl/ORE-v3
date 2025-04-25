#include <glad/glad.h>
#include <ore/gl/render/RenderState.h>
#include <stdexcept>
#include <ore/gl/GLError.h>
#include "OffscreenRenderBuffer.h"

void ore::gl::OffscreenRenderBuffer::create(int32_t widthPixels, int32_t heightPixels) {
    glGenFramebuffers(1, &id);
    this->width = widthPixels;
    this->height = heightPixels;

    glBindFramebuffer(GL_FRAMEBUFFER, id);

    glGenTextures(1, &colourTexture.id);
    glBindTexture(GL_TEXTURE_2D, colourTexture.id);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, widthPixels, heightPixels, 0, GL_RGB, GL_UNSIGNED_BYTE, nullptr);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, colourTexture.id, 0);

    //glGenRenderbuffers(1, &renderBufferID);
    //glBindRenderbuffer(GL_RENDERBUFFER, renderBufferID);
    //glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT, widthPixels, heightPixels);
    //glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, renderBufferID);

    GLenum DrawBuffers[1] = {GL_COLOR_ATTACHMENT0};
    glDrawBuffers(1, DrawBuffers);

    if(glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) {
        throw std::runtime_error("Framebuffer creation failed!");
    }
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void ore::gl::OffscreenRenderBuffer::activate(bool clear) {
    glBindFramebuffer(GL_FRAMEBUFFER, id);
    glViewport(0, 0, width, height);
    if(clear) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }
}

void ore::gl::OffscreenRenderBuffer::deactivate() {
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void ore::gl::OffscreenRenderBuffer::render(ore::RenderState &renderState) {

}

void ore::gl::OffscreenRenderBuffer::blitAt(uint32_t x, uint32_t y) {
    glBlitNamedFramebuffer(id, 0,// makes OpenGL copying the framebuffer data
                           0, 0, width, height,
                           x, y, x + width, y + height,
                           GL_COLOR_BUFFER_BIT,// you only care about the color data, not the depth data …
                           GL_NEAREST);
}
