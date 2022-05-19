#pragma once

#ifndef MY_PLAYER_INCLUDED
#define MY_PLAYER_INCLUDED

/*Include necessary libraries*/
#include "../../Entities/PlayerBehavior.hpp"
#include "../../CursorStatus.cpp"

/*Include necessary events*/
#include "../../FeshEvents/MouseEvent.cpp"

#include <iostream>

class MyPlayer: public PlayerBehavior {
    public:
        MyPlayer();

        void onMouseEvent(MouseEvent* event) override;
        void onKeyboardEvent(ControllerEvent* event) override;
    private:
        float mouse_sensitivity;

        float xRotate;
        float yRotate;
};
#endif