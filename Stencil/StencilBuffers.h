#pragma once

#ifndef STENCIL_BUFFERS_INCLUDED
#define STENCIL_BUFFERS_INCLUDED

#include "../Libraries/Libs.hpp"

class StencilBuffers {
    public:
        StencilBuffers() = default;

        static void enableDepthTest(const bool enable);
        static void setStencilMask(const int mask);
    private:
        static bool isUsingDepthTest;

        //OpenGL Stuff
        static GLuint w_daStencilMask;
        static GLuint t_daStencilMask;
        static GLint daStencilComparison;

        static GLenum daStencilFunc;
};
#endif