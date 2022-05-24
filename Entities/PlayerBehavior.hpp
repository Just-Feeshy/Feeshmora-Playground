#pragma once

#ifndef PLAYER_BEHAVIOR_INCLUDED
#define PLAYER_BEHAVIOR_INCLUDED

#include "../Objects/EventObject.h"
#include "../Camera.cpp"
#include "Entity.cpp"

#include <cmath>

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

        void setRotation(float yaw, float pitch, float roll) override {
            Model::setRotation(yaw, pitch, roll);

            camera -> setRotation(
                camera -> getPosition(X) + yaw,
                camera -> getPosition(Y) + pitch,
                camera -> getPosition(Z) + roll
            );
        }

        virtual void update(const float& elapsed) override {
            camera -> setPosition(
                getPosition(X) - (cameraOffsetX + cameraOffsetZ) * cos(glm::radians(getRotation(X))),
                getPosition(Y) + cameraOffsetY - (cameraOffsetX + cameraOffsetZ) * sin(glm::radians(getRotation(Y))),
                getPosition(Z)
            );
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