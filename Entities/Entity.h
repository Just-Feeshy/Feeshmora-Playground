#pragma once

#ifndef ENTITY_INCLUDED
#define ENTITY_INCLUDED

#include "../Model/Model.cpp"
#include "../FeshMath/AI/PathFinder.hpp"

class Entity: public Model {
    public:
        Entity();

        void moveForward(const float elapsed) override;
        void moveBackwards(const float elapsed) override;
        void moveLeft(const float elapsed) override;
        void moveRight(const float elapsed) override;

        void setWalkspeed(const float walkspeed);
        float getWalkspeed() const;
    protected:
        float _walkspeed;
};
#endif