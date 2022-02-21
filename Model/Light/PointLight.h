#pragma once

#ifndef POINT_LIGHT_INCLUDED
#define POINT_LIGHT_INCLUDED

#include "Light.h"

class PointLight: public Light {
    public:
        PointLight();
        ~PointLight();

        void setLinear(const float value);
        float getLinear() const;
        void setConstant(const float value);
        float getConstant() const;

        void draw(Shaders* shader) override;

        LightType getType() const override {
            return POINT;
        }
    private:
        float linear = 3.0f;
        float constant = 0.7f;
};
#endif