#pragma once

#ifndef LIGHT_INCLUDED
#define LIGHT_INCLUDED

#include "../../FeshStates/BasicStates.h"

#include "../Model.cpp"
#include "LightType.c"

class Light: public Model {
    public:
        Light() {
            createVAO();
        }
        virtual ~Light() {
            
        };

        //glm::mat3 getLightMatrix();
        //glm::mat4 getMatrix() override;

        void setRotation(float yaw, float pitch, float roll) override {
            movement.rotation = {yaw, pitch, roll};

            glm::vec3 faceFront;
        
            faceFront = glm::vec3(
                sin(glm::radians(-pitch)),
                0,
                cos(glm::radians(pitch))
            );
        
            direction = glm::normalize(faceFront);
            angle = glm::normalize(glm::cross(direction, upwards));
        }

        void setColor(glm::vec3 color) {
            this -> color = color;
        }

        glm::vec3 getColor() const {
            return this -> color;
        }

        void setIntensity(const float value) {
            this -> intensity = value;
        }

        void castLight(const bool value) {
            lightOn = value;
        }

        bool getCastingLight() const {
            return this -> lightOn;
        }

        float getIntensity() const {
            return this -> intensity;
        }

        virtual LightType getType() const {
            return NONE;
        }
    protected:
        glm::vec3 color;

        float intensity = 1.0f;

        bool lightOn = true;
};
#endif