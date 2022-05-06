#pragma once

#ifndef DEFAULT_SHADERS_INCLUDED
#define DEFAULT_SHADERS_INCLUDED

#include "Shaders.cpp"
#include "../Helpers/RenderManager.cpp"

/**
* Main Shader method storage class thing... yea.
*/
class DefaultShaders: public Shaders {
    public:
        DefaultShaders() = default;

        void Init();
        void update();
};
#endif