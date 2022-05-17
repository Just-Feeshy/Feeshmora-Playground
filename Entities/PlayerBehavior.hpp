#pragma once

#ifndef PLAYER_BEHAVIOR_INCLUDED
#define PLAYER_BEHAVIOR_INCLUDED

#include "../Objects/EventObject.h"
#include "../Inputs/InputBackend.cpp"
#include "../Camera.cpp"
#include "Entity.cpp"

#include <memory>

using namespace Feeshmora;

class PlayerBehavior: public Entity, public EventObject {
    public:
        PlayerBehavior() = default;

        void attachCamera(std::unique_ptr<Camera> camera) {
            this -> camera = std::move(camera);
            _window = this -> camera -> getWindow();
        }

        void lockCursor(const bool condition) {
            Input::setMousePos(_window, (double)_window -> width / 2, (double)_window -> height / 2); 
        }

        void implementWindow(WindowDisplay* window) {
            if(camera == nullptr) {
                camera -> implementWindow(window);
            }
                
            _window = window;
        }
    protected:
        std::unique_ptr<Camera> camera;
    private:
        WindowDisplay* _window = 0;
};
#endif