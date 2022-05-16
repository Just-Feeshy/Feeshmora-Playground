#pragma once

#ifndef MOUSE_EVENT_INCLUDED
#define MOUSE_EVENT_INCLUDED

#include "../Libraries/glm-master/glm/vec2.hpp"
#include "../Inputs/InputBackend.cpp"
#include "../FeshMath/MathUtil.hpp"

#include "Event.h"

using namespace Feeshmora;

struct MouseEvent: public Event {
    static MouseEvent* CLICK();
    static MouseEvent* CURSOR();

    void update(WindowDisplay* window, const float elapsed) override;

    double getX() const;
    double getY() const;

    glm::vec2 getMouseAxis();

    private:
        std::string eventType;

        double x;
        double y;
    
        glm::vec2 prevMousePosition;
};
#endif