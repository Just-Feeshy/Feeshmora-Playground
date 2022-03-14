#pragma once

#include "Entity.h"

glm::mat4 Entity::getMatrix() {
    glm::mat4 model(1.0f);

    model = glm::rotate(model, glm::radians(movement.rotation.x), {1, 0, 0});
    model = glm::rotate(model, glm::radians(movement.rotation.y), {0, 1, 0});
    model = glm::rotate(model, glm::radians(movement.rotation.z), {0, 0, 1});

    model = glm::translate(model, -movement.position);

    return model;
}