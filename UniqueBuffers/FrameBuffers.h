#pragma once

#ifndef FRAMEBUFFER_INCLUDED
#define FRAMEBUFFER_INCLUDED

#include "../Graphics/Textures/BackendTextures.cpp"
#include "../Model/Mesh.h"
#include "BufferFunc.hpp"

class FrameBuffers: public Mesh {
    public:
        FrameBuffers();
        ~FrameBuffers();

        void render() override;

        GLuint getFBO() const;

        void setFBO(GLuint FBO);

        void setTexture(Attachments attach, int section, bool bind2D, int level);
    private:
        GLuint textureBuffer;

        GLuint FBO;
        GLuint RBO;
};
#endif