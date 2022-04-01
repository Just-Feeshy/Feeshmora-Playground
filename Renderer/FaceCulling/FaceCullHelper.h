#pragma once

#ifndef FACE_CULL_HELPER_INCLUDED
#define FACE_CULL_HELPER_INCLUDED

#include "../../Libraries/Libs.hpp"
#include "FaceCull.hpp"

class FaceCullHelper {
    public:
        FaceCullHelper() = default;

        static void setFaceCulling(FaceCull facecull);
    private:
        static FaceCull daFaceCull;
};
#endif