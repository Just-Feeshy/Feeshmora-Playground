#pragma once

#ifndef FRAMEBUFFER_INCLUDED
#define FRAMEBUFFER_INCLUDED

#include "../Graphics/Textures/BackendTextures.cpp"
#include "../WindowDisplay.cpp"
#include "../Model/Mesh.h"
#include "BufferFunc.hpp"

class FrameBuffers: public Mesh {
    public:
        FrameBuffers();
        ~FrameBuffers();

        void render() override;

        GLuint getFBO() const;
        GLuint getRBO() const;

        void setFBO(GLuint FBO);
        void setRBO(GLuint RBO);

        void setTexture(WindowDisplay* window, Attachments attach, int section, bool bind2D, int level);

        void implementWindow(WindowDisplay* window) override;

        void draw(Shaders* shader, const int index) override {}
        void update(const float& elapsed) override {}
        void draw(Shaders* shader) override {}
    private:
        Bitmap* bitmap;
        BackendTextures texture;

        GLuint FBO = 0;
        GLuint RBO = 0;
};
#endif