#pragma once

#ifndef PLAYER_BEHAVIOR_INCLUDED
#define PLAYER_BEHAVIOR_INCLUDED

#include "../Objects/EventObject.h"
#include "../Inputs/InputBackend.cpp"
#include "../Camera.cpp"
#include "Entity.cpp"

#include <memory>

class PlayerBehavior: public Entity, public EventObject {
    public:
        PlayerBehavior() = default;

        void attachCamera(std::unique_ptr<Camera> camera) {
            this -> camera = std::move(camera);
            _window = this -> camera -> getWindow();
        }

        void lockCursor() const {
            
        }

        void implementWindow(WindowDisplay* window) {
            camera -> implementWindow(window);
            _window = camera -> getWindow();
        }
    protected:
        std::unique_ptr<Camera> camera;
    private:
        WindowDisplay* _window = 0;
};
#endif