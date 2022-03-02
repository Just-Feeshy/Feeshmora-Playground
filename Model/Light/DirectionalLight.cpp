#pragma once

#include "DirectionalLight.h"

DirectionalLight::DirectionalLight() {
    return;
}

DirectionalLight::~DirectionalLight() {
    return;
}

void DirectionalLight::draw(Shaders* shader, const int index) {
    const std::string thisDirecLight = "direclight[" + std::to_string(index) + "]";

    //Regular Light Stuff
    shader -> uniformFloat(thisDirecLight + ".intensity", this -> intensity);
    shader -> uniformInt(thisDirecLight + ".shouldCast", this -> lightOn);
}