#pragma once

#ifndef OUTLINE_OBJ_INCLUDED
#define OUTLINE_OBJ_INCLUDED

#include "../../Renderer/Shaders/Shaders.cpp"

#include "../../Model/Mesh.h"

class Outline: public Mesh {
    public:
        Outline();
        ~Outline();

        void render();
        void draw(Shaders* shader) override;
    private:
        Shaders* outlineShader;
};
#endif