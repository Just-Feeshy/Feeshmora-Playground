#pragma once

#ifndef MY_PLAYER_CPP_INCLUDED
#define MY_PLAYER_CPP_INCLUDED

#include "headers/MyPlayer.h"

/*Include stuff from the engine*/
using namespace Feeshmora;

MyPlayer::MyPlayer() {
    mouse_sensitivity = 5;
}

void MyPlayer::onMouseEvent(MouseEvent* event) {
    float mouseX = event -> getMouseAxis(X) * mouse_sensitivity;
    float mouseY = event -> getMouseAxis(Y) * mouse_sensitivity;

    yRotate += mouseX;
    xRotate -= mouseY;

    xRotate = MathUtil::clamp(xRotate, -80.0f, 80.0f);

    if(this -> camera != nullptr) {
        
    }
}
#endif