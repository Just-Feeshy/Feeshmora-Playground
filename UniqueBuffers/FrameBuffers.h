#pragma once

#ifndef FRAMEBUFFER_INCLUDED
#define FRAMEBUFFER_INCLUDED

#include "../Model/Mesh.h"
#include "BufferFunc.hpp"

class FrameBuffers: public Mesh {
    public:
        FrameBuffers();
        ~FrameBuffers();

        void render() override;

        GLuint getFBO() const;

        void setFBO(GLuint FBO);

        void bindTexture(Attachments attach, GLuint section, bool bind2D, int level);
    private:
        GLuint textureBuffer;

        GLuint FBO;
        GLuint RBO;
};
#endif