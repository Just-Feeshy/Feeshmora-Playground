#pragma once

#ifndef FRUSTUM_INCLUDED
#define FRUSTUM_INCLUDED

#include "Matrix.cpp"

class Frustum {
    public:
        Frustum() = default;
        ~Frustum() = default;

        void doMatrix(glm::mat4 &m);
}
#endif