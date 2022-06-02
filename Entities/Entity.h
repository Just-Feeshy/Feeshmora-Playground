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
        virtual void moveLeft() override;
        virtual void moveRight() override;

        void setWalkspeed(const float walkspeed);
        float getWalkspeed() const;

        virtual void update(const float& elapsed) override;

        virtual glm::mat4 getMatrix() override;
    protected:
        float _walkspeed;
};
#endif