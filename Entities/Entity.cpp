#pragma once

#ifndef ENTITY_CPP_INCLUDED
#define ENTITY_CPP_INCLUDED

#include "Entity.h"

Entity::Entity() {
    _walkspeed = 1;
}

void Entity::moveForward(const float elapsed) {
    Model::moveForward(elapsed * _walkspeed);
}

void Entity::moveBackwards(const float elapsed) {
    Model::moveBackwards(elapsed * _walkspeed);
}

void Entity::moveLeft(const float elapsed) {
    Model::moveLeft(elapsed * _walkspeed);
}

void Entity::moveRight(const float elapsed) {
    Model::moveRight(elapsed * _walkspeed);
}

void Entity::setWalkspeed(const float walkspeed) {
    _walkspeed = walkspeed;
}

float Entity::getWalkspeed() const {
    return _walkspeed;
}
#endif