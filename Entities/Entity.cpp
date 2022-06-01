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

/*
void moveLeft() {
    //movement.position -= angle * elapsed;
}

void moveRight() {
    //movement.position += angle * elapsed;
}
*/

void Entity::setWalkspeed(const float walkspeed) {
    _walkspeed = walkspeed;
}

float Entity::getWalkspeed() const {
    return _walkspeed;
}

void Entity::update(const float& elapsed) {
    Model::update(elapsed);
}
#endif