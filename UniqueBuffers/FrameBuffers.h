#pragma once

#ifndef FRAMEBUFFER_INCLUDED
#define FRAMEBUFFER_INCLUDED

#include "../Model/Mesh.h"

class FrameBuffers: public Mesh {
    public:
        FrameBuffers();
        ~FrameBuffers();

        void render() override;

        void setFBO(GLuint FBO);
        void setTexture(GLuint texture, GLuint colorSection, bool shouldBind);
    private:
        GLuint FBO;
};
#endif