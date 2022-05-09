#pragma once

#include "RenderManager.h"

FaceCull RenderManager::daFaceCull; 

Blend RenderManager::daSRC;
Blend RenderManager::daDST;

void RenderManager::setFaceCulling(FaceCull facecull) {
    if(facecull == CULL_NONE) {
        glDisable(GL_CULL_FACE);
        daFaceCull = facecull;
        return;
    }else if(daFaceCull == facecull) {
        glEnable(GL_CULL_FACE);
    }

    if(daFaceCull != facecull) {
        glEnable(GL_CULL_FACE);
        daFaceCull = facecull;
        glCullFace(daFaceCull);
    }
}

void RenderManager::blend(Blend src, Blend dst) {
    if(daSRC == src && daDST == daDST) {
        return;
    }

    if(src == BLEND_NONE || dst == BLEND_NONE) {
        glDisable(GL_BLEND);
        return;
    }

    glEnable(GL_BLEND);
    glBlendFunc(src, dst);

    daSRC = src;
    daDST = dst;
}