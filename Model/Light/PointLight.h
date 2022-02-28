#pragma once

#ifndef POINT_LIGHT_INCLUDED
#define POINT_LIGHT_INCLUDED

#include "Light.h"

#include <string.h>

class PointLight: public Light {
    public:
        PointLight();
        ~PointLight();

        void setLinear(const float value) {
            this -> linear = value;
        }
        
        void setConstant(const float value) {
            this -> constant = value;
        }
        
        float getLinear() const {
            return linear;
        }
        
        float getConstant() const {
            return constant;
        }

        virtual void draw(Shaders* shader, const int index) override;

        virtual LightType getType() const override {
            return POINT;
        }
    protected:
        float linear = 3.0f;
        float constant = 0.7f;
};
#endif