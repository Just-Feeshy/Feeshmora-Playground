#pragma once

#ifndef RENDER_MANAGER_INCLUDED
#define RENDER_MANAGER_INCLUDED

#include "../../Libraries/Libs.hpp"
#include "RenderEnums.hpp"

class RenderManager {
    public:
        RenderManager() = default;

        static void setFaceCulling(FaceCull facecull);
        static void blend(Blend src, Blend dst);
    private:
        static FaceCull daFaceCull;

        static Blend daSRC;
        static Blend daDST;
};
#endif