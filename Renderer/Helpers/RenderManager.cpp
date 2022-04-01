#pragma once

#include "RenderManager.h"

FaceCull RenderManager::daFaceCull; 

void RenderManager::setFaceCulling(FaceCull facecull) {
    if(facecull == CULL_NONE) {
        glDisable(GL_CULL_FACE);
        daFaceCull = facecull;
        return;
    }else if(daFaceCull == facecull) {
        glEnable(GL_CULL_FACE);
    }

    if(daFaceCull != facecull) {
        daFaceCull = facecull;
        glCullFace(daFaceCull);
    }
}