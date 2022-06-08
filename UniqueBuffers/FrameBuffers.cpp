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
    glBindFramebuffer(GL_FRAMEBUFFER, this -> FBO);
}

GLuint FrameBuffers::getFBO() const {
    return FBO;
}

void FrameBuffers::setTexture(Attachments attach, int section, bool bind2D, int level) {
    
}
#endif