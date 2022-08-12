#pragma once

#ifndef FPS_INCLUDED
#define FPS_INCLUDED

#include "../Libraries/Libs.hpp"

struct FPS {
    void caculateFPS();
    float getDeltaTime();
    
    int getFramerate() const;

    private:
        int framerate = -1;
        float lastTick = 0;
        float lastTickFPS = 0;
};
#endif