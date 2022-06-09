#pragma once

#ifndef FRAMEBUFFER_INCLUDED_CPP
#define FRAMEBUFFER_INCLUDED_CPP

#include "FrameBuffers.h"

FrameBuffers::FrameBuffers() {
    glGenFramebuffers(1, &FBO);
    setFBO(FBO);
}

FrameBuffers::~FrameBuffers() {
    if(bitmap != nullptr) {
        delete bitmap;
    }
}

void FrameBuffers::render() {
    bitmap = new Bitmap();

    setRBO(RBO);
}

void FrameBuffers::setFBO(GLuint FBO) {
    this -> FBO = FBO;
    
    glBindFramebuffer(GL_FRAMEBUFFER, this -> FBO);
}

void FrameBuffers::setRBO(GLuint RBO) {
    this -> RBO = RBO;

    glGenRenderbuffers(1, &this -> RBO);
    glBindRenderbuffer(GL_RENDERBUFFER, this -> RBO);
}

GLuint FrameBuffers::getFBO() const {
    return FBO;
}

GLuint FrameBuffers::getRBO() const {
    return RBO;
}

void FrameBuffers::implementWindow(WindowDisplay* window) {
    if(bitmap != nullptr) {
        bitmap -> setWidth(window -> getWidth());
        bitmap -> setHeight(window -> getHeight());

        if(RBO != 0) {
            glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, bitmap -> getWidth(), bitmap -> getHeight());
             glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, RBO);
        }
    }
}

void FrameBuffers::setTexture(WindowDisplay* window, Attachments attach, int section, bool bind2D, int level) {
    if(bitmap != nullptr) {
        texture.setBitmap(bitmap);
        texture.createTexture(REGULAR, 1, SPECULAR);
        texture.setupParameters(REGULAR, LINEAR, LINEAR, NO_PARAMS);
        texture.bindTexture(attach, section, bind2D, level);
    }
}
#endif