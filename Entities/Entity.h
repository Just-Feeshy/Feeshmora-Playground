#pragma once

#ifndef ENTITY_INCLUDED
#define ENTITY_INCLUDED

#include "../Model/Model.cpp"
#include "../FeshMath/AI/PathFinder.hpp"

class Entity: public Model {
    public:
        Entity() = default;

        void setRotation(float yaw, float pitch, float roll) override;
};
#endif