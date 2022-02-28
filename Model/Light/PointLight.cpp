#pragma once

#include "PointLight.h"

PointLight::PointLight() {
    return;
}

PointLight::~PointLight() {
    return;
}

void PointLight::draw(Shaders* shader, const int index) {
    const std::string thisPointLight = "pointlight[" + std::to_string(index) + "]";

    shader -> uniformInt(thisPointLight + ".lightEnum", getType());

    shader -> uniformFloat(thisPointLight + ".linear", linear);
    shader -> uniformFloat(thisPointLight + ".constant", constant);

    //Regular Light Stuff
    shader -> uniformVec3(thisPointLight + ".position", glm::vec3(movement.position.x, movement.position.y, movement.position.z));
    shader -> uniformFloat(thisPointLight + ".intensity", this -> intensity);
    shader -> uniformInt(thisPointLight + ".shouldCast", this -> lightOn);
}