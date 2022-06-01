#pragma once

#ifndef MY_PLAYER_CPP_INCLUDED
#define MY_PLAYER_CPP_INCLUDED

#include "headers/MyPlayer.h"

/*Include stuff from the engine*/
using namespace Feeshmora;

MyPlayer::MyPlayer() {
    mouse_sensitivity = 5;

    CursorStatus::lockCursor(true);
}

void MyPlayer::onMouseEvent(MouseEvent* event) {
    //event -> setCursorMode(HIDDEN);

    float mouseX = event -> getMouseAxis(X) * mouse_sensitivity;
    float mouseY = event -> getMouseAxis(Y) * mouse_sensitivity;

    yRotate += mouseX / 2;
    xRotate -= mouseY / 2;

    //std::cout << yRotate << std::endl;
    xRotate = MathUtil::clamp(xRotate, -80.0f, 80.0f);

    if(this -> camera != nullptr) {
        this -> setRotation(xRotate, 90 - yRotate, 0.0f);
        this -> camera -> setRotation(xRotate, yRotate, 0.0f);
    }
}

void MyPlayer::onKeyboardEvent(ControllerEvent* event) {
    //PathFinder::getAngleThroughPath(badman -> getPosition(), daCamera -> getPosition()).y

    if(event -> getKeyID() == Keys::W) {
        this -> moveForward();
    }

    if(event -> getKeyID() == Keys::S) {
        this -> moveBackwards();
    }
}
#endif