#pragma once

#include "DefaultShaders.h"

void DefaultShaders::Init() {
    StencilBuffers::enableDepthTest(true);

    glDepthFunc(GL_LESS);

    StencilBuffers::enableStencilTest(true);
    StencilBuffers::setStencilOp(KEEP, KEEP, REPLACE);

    RenderManager::setFaceCulling(CULL_FRONT);
    
    glFrontFace(GL_CW);

    
}

void DefaultShaders::update() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
}