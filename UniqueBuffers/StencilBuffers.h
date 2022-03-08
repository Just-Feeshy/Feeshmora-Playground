#pragma once

#ifndef STENCIL_BUFFERS_INCLUDED
#define STENCIL_BUFFERS_INCLUDED

#include "../Libraries/Libs.hpp"
#include "BufferFunc.hpp"
#include "StencilFail.hpp"

class StencilBuffers {
    public:
        StencilBuffers() = default;

        static void enableDepthTest(const bool enable);
        static void enableStencilTest(const bool enable);
        static void setStencilMask(const int mask);

        static void setStencilFunc(const BufferFunc stencil, const int comparison, const int mask);
        static void setStencilOp(const StencilFail sFail, const StencilFail dpFail, const StencilFail pass);
    private:
        static bool isUsingDepthTest;
        static bool isUsingStencilTest;

        //OpenGL Stuff
        static GLuint w_daStencilMask;
        static GLuint t_daStencilMask;

        //Stencil Function
        static BufferFunc stencilFunction;
        static int daStencilComparison;

        //Stencil Operation
        static StencilFail daStencilFail;
        static StencilFail daStencilPassDepthFail;
        static StencilFail daStencilPass;
};
#endif