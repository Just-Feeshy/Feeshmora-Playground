#pragma once

#ifndef PLAYER_INCLUDED
#define PLAYER_INCLUDED

#include "../Util/Direction.hpp"
#include "Entity.cpp"

#include <memory>

class Player: public Entity {
    public:
        Player();

        void setActionEvent();
    protected:
        unique_ptr<Camera> daCamera;

        
}
#endif