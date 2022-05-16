#pragma once

#ifndef PLAYER_CPP_INCLUDED
#define PLAYER_CPP_INCLUDED

#include "Player.h"

Player::Player() {
    return;
}

void Player::attachCamera(std::unique_ptr<Camera> camera) {
    daCamera = std::move(camera);
}
#endif