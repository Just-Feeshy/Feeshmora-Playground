#pragma once

#ifndef SPOT_LIGHT_INCLUDED
#define SPOT_LIGHT_INCLUDED

#include "Light.h"

#include <string.h>

class SpotLight: public Light {
    public:
        SpotLight();
        ~SpotLight();

        void draw(Shaders* shader, const int index) override;

        LightType getType() const override {
            return SPOT;
        }
};
#endif