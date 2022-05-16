#pragma once

#ifndef PLAYER_INCLUDED
#define PLAYER_INCLUDED

#include "../Objects/EventObject.h"
#include "../Camera.cpp"
#include "Entity.cpp"

#include <memory>

class Player: public Entity, public EventObject {
    public:
        Player();

        void attachCamera(std::unique_ptr<Camera> camera);
    protected:
        std::unique_ptr<Camera> daCamera;
};
#endif