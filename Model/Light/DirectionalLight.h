#pragma once

#ifndef DIREC_LIGHT_INCLUDED
#define DIREC_LIGHT_INCLUDED

#include "Light.h"

#include <string.h>

class DirectionalLight: public Light {
    public:
        DirectionalLight();
        ~DirectionalLight();

        virtual void draw(Shaders* shader, const int index) override;

        virtual LightType getType() const override {
            return DIRECTIONAL;
        }
};
#endif