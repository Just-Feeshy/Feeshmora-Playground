#pragma once

#ifndef MY_PLAYER_INCLUDED
#define MY_PLAYER_INCLUDED

#include "../../Entities/PlayerBehavior.hpp"

class MyPlayer: public PlayerBehavior {
    public:
        MyPlayer();

        
    private:
        float mouse_sensitivity;
}
#endif