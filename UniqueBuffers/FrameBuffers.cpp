#pragma once

#ifndef FRAMEBUFFER_INCLUDED_CPP
#define FRAMEBUFFER_INCLUDED_CPP

#include "FrameBuffers.h"

FrameBuffers::FrameBuffers() {
    glGenFramebuffers(1, &FBO);
    setFBO(FBO);
}

FrameBuffers::~FrameBuffers() {
    if(FBO != 0 && FBO) {

    }
}

void FrameBuffers::render() {

}

void FrameBuffers::setFBO(GLuint FBO) {
    this -> FBO = FBO;
    glBindBuffer(GL_FRAMEBUFFER, this -> FBO);
}

GLuint FrameBuffers::getFBO() const {
    return FBO;
}

void FrameBuffers::bindTexture(Attachments attach, int section, bool bind2D, int level) {
    GLenum attachSection = attach + section;

    glBindTexture(GL_TEXTURE_2D, textureBuffer);

    if(bind2D) {
        glFramebufferTexture2D(GL_FRAMEBUFFER, attachSection, GL_TEXTURE_2D, textureBuffer, level);
    }else {
        glFramebufferTexture(GL_FRAMEBUFFER, attachSection, textureBuffer, level);
    }
}
#endif