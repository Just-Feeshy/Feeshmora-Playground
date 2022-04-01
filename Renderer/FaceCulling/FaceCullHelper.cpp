#pragma once

#include "FaceCullHelper.h"

FaceCull FaceCullHelper::daFaceCull; 

void FaceCullHelper::setFaceCulling(FaceCull facecull) {
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