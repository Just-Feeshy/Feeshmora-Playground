#pragma once

#ifndef ENTITY_CPP_INCLUDED
#define ENTITY_CPP_INCLUDED

#include "Entity.h"

Entity::Entity() {
    Entity::Model();
    _walkspeed = 1;
}

void Entity::moveForward() {
    movement.position += direction * getElapsed() * _walkspeed;
}

void Entity::moveBackwards() {
    movement.position -= direction * getElapsed() * _walkspeed;
}

void Entity::moveRight() {
    movement.position += angle * getElapsed() * _walkspeed;
}

void Entity::moveLeft() {
    movement.position -= angle * getElapsed() * _walkspeed;
}

void Entity::setWalkspeed(const float walkspeed) {
    this -> _walkspeed = walkspeed;
}

float Entity::getWalkspeed() const {
    return _walkspeed;
}

/**
* Test n' Stuff
*/
glm::mat4 Entity::getMatrix() {
    return Model::getMatrix();
}

void Entity::update(const float& elapsed) {
    Model::update(elapsed);
}
#endif