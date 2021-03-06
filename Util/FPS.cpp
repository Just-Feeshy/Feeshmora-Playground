#pragma once

#include "FPS.h"

namespace GlobalFPS {
    float getDeltaTime() {
        FPS fps;
        
        return fps.getDeltaTime();
    }
}

void FPS::caculateFPS() {
    float currentTime = glfwGetTime();
    if ((currentTime - lastTickFPS) > 1) {
      framerate = -1;
      lastTickFPS = currentTime;
    }else {
        framerate++;
    }
}

int FPS::getFramerate() const {
    return framerate;
}

float FPS::getDeltaTime() { //Simple
    float curTick = glfwGetTime();
    float returnTick = curTick - lastTick;
    lastTick = curTick;
    return returnTick;
}