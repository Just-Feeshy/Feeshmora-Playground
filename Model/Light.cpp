#include "Light.h"

Light::Light() {
    return;
}

Light::Light(const LightType type) {
    return;
}

Light::~Light() {
    return;
}

void Light::setLightToBe(const LightType type) {
    this -> type = type;
}

void Light::render() {
    return;
}

void Light::draw(Shaders* shader) {
    shader -> uniformInt("light.lightEnum", type);

    shader -> uniformFloat("light.linear", linear);
    shader -> uniformFloat("light.constant", constant);

    shader -> uniformVec3("light.position", glm::vec3(movement.position.x, movement.position.y, movement.position.z));
    shader -> uniformFloat("light.brightness", this -> brightness);
}

glm::mat3 Light::getLightMatrix() {
    glm::mat3 light(1.0f);

    light[0] = glm::vec3(movement.position); //Position
    light[1] = glm::vec3(color); //Color
    light[2] = glm::vec3(movement.rotation); //Rotation

    return light;
}

void Light::setColor(glm::vec3 color) {
    this -> color = color;
}

void Light::setBrightness(const float value) {
    this -> brightness = value;
}

void Light::setLinear(const float value) {
    this -> linear = value;
}

void Light::setConstant(const float value) {
    this -> constant = value;
}

float Light::getBrightness() const {
    return brightness;
}

glm::vec3 Light::getColor() const {
    return color;
}

float Light::getLinear() const {
    return linear;
}

float Light::getConstant() const {
    return constant;
}

LightType Light::getType() const {
    return type;
}