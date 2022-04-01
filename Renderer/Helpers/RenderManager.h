#pragma once

#ifndef FACE_CULL_HELPER_INCLUDED
#define FACE_CULL_HELPER_INCLUDED

#include "../../Libraries/Libs.hpp"
#include "RenderEnums.hpp"

class RenderManager {
    public:
        RenderManager() = default;

        static void setFaceCulling(FaceCull facecull);
    private:
        static FaceCull daFaceCull;
};
#endif