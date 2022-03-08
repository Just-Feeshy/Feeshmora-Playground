#pragma once

#include "StencilBuffers.h"

bool StencilBuffers::isUsingDepthTest = false;

//OpenGL Stuff
GLuint StencilBuffers::w_daStencilMask = 0;
GLuint StencilBuffers::t_daStencilMask = 0;
GLint StencilBuffers::daStencilComparison = 0;

void StencilBuffers::enableDepthTest(const bool enable) {
    if(isUsingDepthTest != enable) {
        if(enable) {
            glEnable(GL_DEPTH_TEST);
        }else {
            glDisable(GL_DEPTH_TEST);
        }

        isUsingDepthTest = enable;
    }
}

void StencilBuffers::setStencilMask(const int mask) {
    const GLuint maskIS = (GLuint)mask;
    
    if(w_daStencilMask != maskIS) {
        glStencilMask(maskIS);
        
        w_daStencilMask = maskIS;
    }
}