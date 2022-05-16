#pragma once

#ifndef PLAYER_CPP_INCLUDED
#define PLAYER_CPP_INCLUDED

#include "Player.h"

Player::Player() {
    daCamera = std::make_unique<Camera>();
}
#endif