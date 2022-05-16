#pragma once

#ifndef CAMERA_CPP_INCLUDED
#define CAMERA_CPP_INCLUDED

#include "Camera.h"

Camera::Camera() {
    movement.position = {0.0f, 0.0f, 0.0f};
}

void Camera::implementWindow(WindowDisplay* window) {
    thisWindow = window;
    projection = makeProjection();
}

void Camera::setRotation(float yaw, float pitch, float roll) {
    movement.rotation = {yaw, pitch, roll};

    glm::vec3 faceFront;

    faceFront = glm::vec3(
        sin(glm::radians(-pitch)),
        0,
        cos(glm::radians(pitch))
    );

    direction = glm::normalize(faceFront);
    angle = glm::normalize(glm::cross(direction, upwards));
    cameraUP = glm::normalize(glm::cross(angle, direction));
}

glm::mat4 Camera::makeProjection() {
    float width = (float)thisWindow -> width;
    float height = (float)thisWindow -> height;
    float fov = (float)thisWindow -> FOV;
    float rDistance = (float)thisWindow -> renderDistance;

    return Matrix::perspective(fov, width / height, 0.1f, rDistance * 100.0f);
}

glm::mat4 Camera::getMatrix() {
    glm::mat4 model(1.0f);

    model = glm::rotate(model, glm::radians(movement.rotation.x), {1, 0, 0});
    model = glm::rotate(model, glm::radians(movement.rotation.y), {0, 1, 0});
    model = glm::rotate(model, glm::radians(movement.rotation.z), {0, 0, 1});

    model = glm::translate(model, -movement.position);

    return model;
}

void Camera::addShaders(const Shaders shader) {
    shaderGroup.push_back(shader);
}

void Camera::draw(Shaders* shader) {
    shader -> uniformFloat("depthy.near", 0.1f);
    shader -> uniformFloat("depthy.far", thisWindow -> renderDistance / 2);
}

void Camera::update(float elapsed) {
    Model::update(elapsed);
    
    view = getMatrix();
    projection = makeProjection();
    pView = projection * view;
}
#endif