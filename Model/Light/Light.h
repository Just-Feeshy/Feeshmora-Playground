#pragma once

#ifndef LIGHT_INCLUDED
#define LIGHT_INCLUDED

#include "../Model.cpp"

enum LightType {
    NONE = -1, //Basically light Python
    POINT = 0,
    SPOT = 1
};

class Light: public Model {
    public:
        Light() {
            createVAO();
        }
        virtual ~Light() {};

        //glm::mat3 getLightMatrix();
        //glm::mat4 getMatrix() override;

        void setColor(glm::vec3 color) {
            this -> color = color;
        }

        glm::vec3 getColor() const {
            return this -> color;
        }

        void setIntensity(const float value) {
            this -> intensity = value;
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
};
#endif