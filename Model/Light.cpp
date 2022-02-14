#include "Light.h"

Light::Light() {
    return;
}

Light::~Light() {
    return;
}

void Light::render() {
    MeshVertices lv;

    lv.addVertexRow(-0.25f, 0.25f, -0.25f);
    lv.addTexCoordRow(0.0f, 1.0f);
    lv.storeThisArray();

    lv.addVertexRow(-0.25f, -0.25f, -0.25f);
    lv.addTexCoordRow(0.0f, 0.0f);
    lv.storeThisArray();

    lv.addVertexRow(-0.25f, -0.25f, 0.25f);
    lv.addTexCoordRow(1.0f, 0.0f);
    lv.storeThisArray();

    lv.addVertexRow(-0.25f, 0.25f, 0.25f);
    lv.addTexCoordRow(1.0f, 1.0f);
    lv.storeThisArray();

    lv.storeIndices(0, 1, 3);
    lv.storeIndices(3, 1, 2);

    this -> create(lv);
}

void Light::draw(Shaders* shader) {
    shader -> uniformMat3("lightMatrix", this -> getLightMatrix());
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

glm::vec3 Light::getColor() const {
    return color;
}