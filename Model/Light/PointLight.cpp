#pragma once

#include "PointLight.h"

PointLight::PointLight() {
    return;
}

PointLight::~PointLight() {
    return;
}

void PointLight::draw(Shaders *shader) {
    shader -> uniformInt("MAXIMUM_POINTLIGHT", 1);

    shader -> uniformInt("pointlight[0].lightEnum", getType());

    shader -> uniformFloat("pointlight[0].linear", linear);
    shader -> uniformFloat("pointlight[0].constant", constant);

    //Regular Light Stuff
    shader -> uniformVec3("pointlight[0].position", glm::vec3(movement.position.x, movement.position.y, movement.position.z));
    shader -> uniformFloat("pointlight[0].intensity", this -> intensity);
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