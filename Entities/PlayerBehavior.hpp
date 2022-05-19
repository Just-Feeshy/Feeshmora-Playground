#pragma once

#ifndef PLAYER_BEHAVIOR_INCLUDED
#define PLAYER_BEHAVIOR_INCLUDED

#include "../Objects/EventObject.h"
#include "../Camera.cpp"
#include "Entity.cpp"

class PlayerBehavior: public Entity, public EventObject {
    public:
        PlayerBehavior() {
            cameraOffsetX = 0;
            cameraOffsetY = 0;
            cameraOffsetZ = 0;
        };

        ~PlayerBehavior() {
            camera = nullptr;
        }

        void attachCamera(Camera* camera) {
            this -> camera = camera;
            _window = this -> camera -> getWindow();
        }

        void implementWindow(WindowDisplay* window) override {
            if(camera == nullptr) {
                camera -> implementWindow(window);
            }
                
            _window = window;
        }

        virtual void update(const float& elapsed) override {
            camera -> setPosition(movement.position.x - cameraOffsetX, movement.position.y - cameraOffsetY, movement.position.z - cameraOffsetZ);
        }
    protected:
        Camera* camera;
    private:
        WindowDisplay* _window = 0;

        float cameraOffsetX;
        float cameraOffsetY;
        float cameraOffsetZ;
};
#endif