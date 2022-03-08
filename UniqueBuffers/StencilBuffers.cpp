#pragma once

#include "StencilBuffers.h"

bool StencilBuffers::isUsingDepthTest = false;
bool StencilBuffers::isUsingStencilTest = false;

//OpenGL Stuff
GLuint StencilBuffers::w_daStencilMask = 0;
GLuint StencilBuffers::t_daStencilMask = 0;
GLint StencilBuffers::daStencilComparison = 0;

BufferFunc StencilBuffers::stencilFunction;

StencilFail StencilBuffers::daStencilFail;
StencilFail StencilBuffers::daStencilPassDepthFail;
StencilFail StencilBuffers::daStencilPass;

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

void StencilBuffers::enableStencilTest(const bool enable) {
    if(isUsingStencilTest != enable) {
        if(enable) {
            glEnable(GL_STENCIL_TEST);
        }else {
            glDisable(GL_STENCIL_TEST);
        }

        isUsingStencilTest = enable;
    }
}

void StencilBuffers::setStencilFunc(const BufferFunc stencil, const int comparison, const int mask) {
    const GLuint comparisonIS = (GLuint)comparison;

    if(stencil != stencilFunction || comparisonIS != daStencilComparison || t_daStencilMask != mask) {
        glStencilFunc(stencil, comparisonIS, mask);

        stencilFunction = stencil;
        daStencilComparison = comparisonIS;
        t_daStencilMask = mask;
    }
}

void StencilBuffers::setStencilOp(const StencilFail sFail, const StencilFail dpFail, const StencilFail pass) {
    if(sFail != daStencilFail || dpFail != daStencilPassDepthFail || pass != daStencilPass) {
        glStencilOp(sFail, dpFail, pass);

        daStencilFail = sFail;
        daStencilPassDepthFail = dpFail;
        daStencilPass = pass;
    }
}