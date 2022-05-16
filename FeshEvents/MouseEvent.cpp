#pragma once

#ifndef MOUSE_EVENT_CPP_INCLUDED
#define MOUSE_EVENT_CPP_INCLUDED

#include "MouseEvent.h"

MouseEvent::MouseEvent() {
    sensitivity = 0.5f;
}

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

void MouseEvent::setSensitivity(const float s) {
    this -> sensitivity = s;
}

double MouseEvent::getX() const {
    return x;
}

double MouseEvent::getY() const {
    return y;
}

float MouseEvent::getSensitivity() const {
    return sensitivity;
}

glm::vec2 MouseEvent::getMouseAxis() {
    glm::vec2 diff = glm::vec2((float)(x - prevMousePosition.x), (float)(y - prevMousePosition.y));

    diff.x = MathUtil::clamp(diff.x, -sensitivity, sensitivity);
    diff.x = MathUtil::remap(diff.x, -sensitivity, sensitivity, -1.0f, 1.0f);
    diff.y = MathUtil::clamp(diff.y, -sensitivity, sensitivity);
    diff.y = MathUtil::remap(diff.y, -sensitivity, sensitivity, -1.0f, 1.0f);

    prevMousePosition = glm::vec2(x, y);
    
    return diff;
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