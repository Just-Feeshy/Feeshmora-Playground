#pragma once

#include "PointLight.h"

PointLight::PointLight() {
    return;
}

PointLight::~PointLight() {
    return;
}

void PointLight::draw(Shaders *shader) {
    shader -> uniformInt("light.lightEnum", getType());

    shader -> uniformFloat("light.linear", linear);
    shader -> uniformFloat("light.constant", constant);

    //Regular Light Stuff
    shader -> uniformVec3("light.position", glm::vec3(movement.position.x, movement.position.y, movement.position.z));
    shader -> uniformFloat("light.intensity", this -> intensity);
}

void PointLight::setLinear(const float value) {
    this -> linear = value;
}

void PointLight::setConstant(const float value) {
    this -> constant = value;
}

float PointLight::getLinear() const {
    return linear;
}

float PointLight::getConstant() const {
    return constant;
}