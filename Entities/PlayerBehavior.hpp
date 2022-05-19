#pragma once

#ifndef PLAYER_BEHAVIOR_INCLUDED
#define PLAYER_BEHAVIOR_INCLUDED

#include "../Objects/EventObject.h"
#include "../Camera.cpp"
#include "Entity.cpp"

class PlayerBehavior: public Entity, public EventObject {
    public:
        PlayerBehavior() = default;

        ~PlayerBehavior() {
            camera = nullptr;
        }

        void attachCamera(Camera* camera) {
            this -> camera = camera;
            _window = this -> camera -> getWindow();
        }

        void implementWindow(WindowDisplay* window) {
            if(camera == nullptr) {
                camera -> implementWindow(window);
            }
                
            _window = window;
        }
    protected:
        Camera* camera;
    private:
        WindowDisplay* _window = 0;
};
#endif