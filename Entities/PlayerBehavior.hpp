#pragma once

#ifndef PLAYER_BEHAVIOR_INCLUDED
#define PLAYER_BEHAVIOR_INCLUDED

#include "../FeshMath/MathUtil.hpp"
#include "../Objects/EventObject.h"
#include "../Camera.cpp"
#include "Entity.cpp"

class PlayerBehavior: public Entity, public EventObject {
    public:
        PlayerBehavior() {
            cameraOffsetPosition = {0.0f, 0.0f, 0.0f};
            cameraRotation = {0.0f, 0.0f, 0.0f};
            playerHead_y = 0.0f;
        };

        ~PlayerBehavior() {
            camera = nullptr;
        }

        void implementWindow(WindowDisplay* window) override {
            if(camera == nullptr) {
                camera -> implementWindow(window);
            }
                
            _window = window;
        }

        virtual void update(const float& elapsed) override {
            Entity::update(elapsed);
            
            if(camera != nullptr) {
                camera -> setPosition(
                    getPosition(X) - (cameraOffsetPosition.x + cameraOffsetPosition.z) * cos(glm::radians(camera -> getRotation(X))),
                    getPosition(Y) + cameraOffsetPosition.y - (cameraOffsetPosition.x + cameraOffsetPosition.z) * sin(glm::radians(camera -> getRotation(Y))),
                    getPosition(Z) - (cameraOffsetPosition.x + cameraOffsetPosition.z) * sin(glm::radians(-camera -> getRotation(Z)))
                );
            }
        }

        //Camera stuff
        void attachCamera(Camera* camera) {
            playerHead_y = camera -> getPosition(Y);
            this -> camera = camera;
            _window = this -> camera -> getWindow();
        }     
    protected:
        Camera* camera;
    private:
        WindowDisplay* _window = 0;

        glm::vec3 cameraOffsetPosition;
        glm::vec3 cameraRotation;

        float playerHead_y;
};
#endif