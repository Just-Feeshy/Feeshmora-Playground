#pragma once

#include "SpotLight.h"

SpotLight::SpotLight() {
    return;
}

SpotLight::~SpotLight() {
    return;
}

void SpotLight::draw(Shaders* shader, const int index) {
    const std::string thisSpotLight = "spotlight[" + std::to_string(index) + "]";

    //Regular Light Stuff
    shader -> uniformVec3(thisSpotLight + ".position", glm::vec3(movement.position.x, movement.position.y, movement.position.z));
    shader -> uniformFloat(thisSpotLight + ".intensity", this -> intensity);
    shader -> uniformInt(thisSpotLight + ".shouldCast", this -> lightOn);
}