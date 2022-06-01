#pragma once

#ifndef ENTITY_INCLUDED
#define ENTITY_INCLUDED

#include "../FeshMath/AI/PathFinder.hpp"
#include "../Model/Model.cpp"

class Entity: public Model {
    public:
        Entity();
        virtual ~Entity() = default;

        virtual void moveForward() override;
        virtual void moveBackwards() override;
        //void moveLeft() override;
        //void moveRight() override;

        void setWalkspeed(const float walkspeed);
        float getWalkspeed() const;

        virtual void update(const float& elapsed) override;
    protected:
        float _walkspeed;
};
#endif