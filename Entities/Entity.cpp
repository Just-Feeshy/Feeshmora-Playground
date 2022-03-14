#pragma once

#include "Entity.h"

void Entity::setRotation(float yaw, float pitch, float roll) {
    movement.rotation = {yaw, pitch, roll};

    glm::vec3 faceFront;

    faceFront = glm::vec3(
        cos(glm::radians(pitch)),
        0,
        sin(glm::radians(-pitch))
    );

    direction = glm::normalize(faceFront);
    angle = glm::normalize(glm::cross(direction, upwards));
}