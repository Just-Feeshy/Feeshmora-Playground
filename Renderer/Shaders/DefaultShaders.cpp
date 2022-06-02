#pragma once

#include "DefaultShaders.h"

void DefaultShaders::Init() {
    StencilBuffers::enableDepthTest(true);

    glEnable(GL_CULL_FACE);
    
    glFrontFace(GL_CW);

    glDepthFunc(GL_LESS);
}

void DefaultShaders::update() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
}