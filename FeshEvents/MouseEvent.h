#pragma once

#ifndef MOUSE_EVENT_INCLUDED
#define MOUSE_EVENT_INCLUDED

#include "../Libraries/glm-master/glm/vec2.hpp"
#include "../Inputs/InputBackend.cpp"
#include "../FeshMath/MathUtil.hpp"
#include "../Util/FeshAxis.hpp"
#include "../Application.cpp"

#include "Event.h"

using namespace Feeshmora;

struct MouseEvent: public Event {
    static MouseEvent* CLICK();
    static MouseEvent* CURSOR();

    void update(WindowDisplay* window, const float elapsed) override;

    double getX() const;
    double getY() const;
    double getRawX() const;
    double getRawY() const;
    double getRawX(WindowDisplay* window) const;
    double getRawY(WindowDisplay* window) const;

    void setMouseAxis(const float& x, const float &y);
    float getMouseAxis(const FeshAxis& axis);

    void execute() override;

    private:
        std::string eventType;

        double x;
        double y;
    
        glm::vec2 _axisMousePosition;
};
#endif