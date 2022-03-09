#pragma once

#include "DefaultShaders.h"

void DefaultShaders::Init() {
    StencilBuffers::enableDepthTest(true);
    StencilBuffers::enableStencilTest(true);

    glDepthFunc(GL_LESS);

    StencilBuffers::setStencilFunc(NOT_EQUAL, 1, 0xFF);
    StencilBuffers::setStencilOp(KEEP, KEEP, REPLACE);
    
    glFrontFace(GL_CW);
}

void DefaultShaders::update() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
}