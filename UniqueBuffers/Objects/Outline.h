#pragma once

#ifndef OUTLINE_OBJ_INCLUDED
#define OUTLINE_OBJ_INCLUDED

#include "../../Renderer/Shaders/Shaders.cpp"
#include "../../FeshMath/Matrix.cpp"

#include "../../Model/Mesh.h"

class Outline: public Mesh {
    public:
        Outline();
        ~Outline();

        void render() override;
        void update() override;
        void draw(Shaders* shader) override;
        void draw(Shaders* shader, const int index)
override;
};
#endif