#ifndef FPS_INCLUDED
#define FPS_INCLUDED

#include "../Libraries/Libs.hpp"

struct FPS {
    int framerate = -1;
    float lastTick = 0;
    float lastTickFPS = 0;

    void caculateFPS();
    float getDeltaTime();
};
#endif