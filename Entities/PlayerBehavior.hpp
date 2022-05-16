#pragma once

#ifndef PLAYER_BEHAVIOR_INCLUDED
#define PLAYER_BEHAVIOR_INCLUDED

#include "../Objects/EventObject.h"
#include "../Camera.cpp"
#include "Entity.cpp"

#include <memory>

class PlayerBehavior: public Entity, public EventObject {
    public:
        PlayerBehavior() = default;

        void attachCamera(std::unique_ptr<Camera> camera) {
            daCamera = std::move(camera);
        }
    protected:
        std::unique_ptr<Camera> daCamera;
};
#endif