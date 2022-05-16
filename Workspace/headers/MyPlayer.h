#pragma once

#ifndef MY_PLAYER_INCLUDED
#define MY_PLAYER_INCLUDED

/*Include necessary libraries*/
#include "../../Entities/PlayerBehavior.hpp"

/*Include necessary events*/
#include "../../FeshEvents/MouseEvent.cpp"

class MyPlayer: public PlayerBehavior {
    public:
        MyPlayer();

        void onMouseEvent(MouseEvent* event) override;
    private:
        float mouse_sensitivity;

        float xRotate;
        float yRotate;
};
#endif