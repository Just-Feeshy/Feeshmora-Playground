#pragma once

#ifndef MOUSE_EVENT_CPP_INCLUDED
#define MOUSE_EVENT_CPP_INCLUDED

#include "MouseEvent.h"

#define DEFAULT_MOUSE_SENSITIVITY 0.5f

MouseEvent* MouseEvent::CLICK() {
    MouseEvent* event = new MouseEvent();
    event -> eventType = "click";
    return event;
}

MouseEvent* MouseEvent::CURSOR() {
    MouseEvent* event = new MouseEvent();
    event -> eventType = "cursor";
    return event;
}

double MouseEvent::getX() const {
    return x;
}

double MouseEvent::getY() const {
    return y;
}

double MouseEvent::getRawX() const {
    return Input::getMousePosXY(Application::daWindow, X);
}

double MouseEvent::getRawY() const {
    return Input::getMousePosXY(Application::daWindow, Y);
}

double MouseEvent::getRawX(WindowDisplay* window) const {
    return Input::getMousePosXY(window, X);
}

double MouseEvent::getRawY(WindowDisplay* window) const {
    return Input::getMousePosXY(window, Y);
}

void MouseEvent::execute() {
    eventOBJ -> onMouseEvent(this);
}

void MouseEvent::setMouseAxis(const float& x, const float &y) {
    _axisMousePosition = glm::vec2(x, y);
}

float MouseEvent::getMouseAxis(const FeshAxis& axis) {
    glm::vec2 diff = glm::vec2((float)(x - _axisMousePosition.x), (float)(y - _axisMousePosition.y));

    diff.x = MathUtil::clamp(diff.x, -DEFAULT_MOUSE_SENSITIVITY, DEFAULT_MOUSE_SENSITIVITY);
    diff.x = MathUtil::remap(diff.x, -DEFAULT_MOUSE_SENSITIVITY, DEFAULT_MOUSE_SENSITIVITY, -1.0f, 1.0f);
    diff.y = MathUtil::clamp(diff.y, -DEFAULT_MOUSE_SENSITIVITY, DEFAULT_MOUSE_SENSITIVITY);
    diff.y = MathUtil::remap(diff.y, -DEFAULT_MOUSE_SENSITIVITY, DEFAULT_MOUSE_SENSITIVITY, -1.0f, 1.0f);

    _axisMousePosition = glm::vec2(x, y);

    if(axis == Y)
        return diff.y;
    else
        return diff.x;
}

void MouseEvent::update(WindowDisplay* window, const float elapsed) {
    x = getRawX(window);
    y = getRawY(window);
    
    if(eventType == "cursor") {
        execute();
    }

    if(eventType == "click") {
        if(Input::getMouseButton(window, 1, 1)) {
            execute();
        }
    }
    
    Event::update(window, elapsed);
}
#endif