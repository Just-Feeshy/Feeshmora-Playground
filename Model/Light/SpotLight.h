#pragma once

#ifndef SPOT_LIGHT_INCLUDED
#define SPOT_LIGHT_INCLUDED

#include "Light.h"

#include <string.h>

class SpotLight: public PointLight {
    public:
        SpotLight();
        ~SpotLight();

        void setCutOff(const float value) {
            this -> cutOff = value;
        }
        
        void setOuterCutOff(const float value) {
            this -> outerCutOff = value;
        }

        float getCutOff() const {
            return this -> cutOff;
        }

        float getOuterCutOff() const {
            return this -> outerCutOff;
        }

        void draw(Shaders* shader, const int index) override;

        LightType getType() const override {
            return SPOT;
        }
    protected:
        float cutOff = 0.0f;
        float outerCutOff = 0.0f;
};
#endif