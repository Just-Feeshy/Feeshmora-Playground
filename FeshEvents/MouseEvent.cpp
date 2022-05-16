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

float MouseEvent::getMouseAxis(FeshAxis& axis) {
    glm::vec2 diff = glm::vec2((float)(x - prevMousePosition.x), (float)(y - prevMousePosition.y));

    diff.x = MathUtil::clamp(diff.x, -DEFAULT_MOUSE_SENSITIVITY, DEFAULT_MOUSE_SENSITIVITY);
    diff.x = MathUtil::remap(diff.x, -DEFAULT_MOUSE_SENSITIVITY, DEFAULT_MOUSE_SENSITIVITY, -1.0f, 1.0f);
    diff.y = MathUtil::clamp(diff.y, -DEFAULT_MOUSE_SENSITIVITY, DEFAULT_MOUSE_SENSITIVITY);
    diff.y = MathUtil::remap(diff.y, -DEFAULT_MOUSE_SENSITIVITY, DEFAULT_MOUSE_SENSITIVITY, -1.0f, 1.0f);

    prevMousePosition = glm::vec2(x, y);

    if(axis == Y)
        return diff.y;
    else
        return diff.x;
}

void MouseEvent::update(WindowDisplay* window, const float elapsed) {
    x = Input::getMousePosXY(window, X);
    y = Input::getMousePosXY(window, Y);
    
    if(eventType == "cursor" && (x != prevMousePosition.x || y != prevMousePosition.y)) {
        execute();
    }

    if(eventType == "click") {
        if(Input::getMouseButton(window, 1, 1)) {
            execute();
        }
    }

    prevMousePosition.x = x;
    prevMousePosition.y = y;
    
    Event::update(window, elapsed);
}
#endif