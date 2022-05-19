#pragma once

#ifndef MOUSE_EVENT_CPP_INCLUDED
#define MOUSE_EVENT_CPP_INCLUDED

#include "MouseEvent.h"

#define DEFAULT_MOUSE_SENSITIVITY 0.5f

MouseEvent::MouseEvent() {
    Input = new InputBackend();
}

MouseEvent::~MouseEvent() {
    if(Input != nullptr) {
        delete Input;
    }
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

double MouseEvent::getX() const {
    return x;
}

double MouseEvent::getY() const {
    return y;
}

double MouseEvent::getRawX() const {
    return Input -> getMousePosXY(Application::daWindow, X);
}

double MouseEvent::getRawY() const {
    return Input -> getMousePosXY(Application::daWindow, Y);
}

double MouseEvent::getRawX(WindowDisplay* window) const {
    return Input -> getMousePosXY(window, X);
}

double MouseEvent::getRawY(WindowDisplay* window) const {
    return Input -> getMousePosXY(window, Y);
}

void MouseEvent::execute() {
    eventOBJ -> onMouseEvent(this);
}

void MouseEvent::setMouseAxis(const float& x, const float &y) {
    _axisMousePosition = glm::vec2(x, y);
}

float MouseEvent::getMouseAxis(const FeshAxis& axis) {
    float diff;

    if(axis == Y) {
        diff = (float)(y - _axisMousePosition.y);
    }else {
        diff = (float)(x - _axisMousePosition.x);
    }

    diff = MathUtil::clamp(diff, -DEFAULT_MOUSE_SENSITIVITY, DEFAULT_MOUSE_SENSITIVITY);
    diff = MathUtil::remap(diff, -DEFAULT_MOUSE_SENSITIVITY, DEFAULT_MOUSE_SENSITIVITY, -1.0f, 1.0f);

    if(axis == Y) {
        _axisMousePosition.y = y;
        return -diff;
    }else {
        _axisMousePosition.x = x;
        return diff;
    }
}

void MouseEvent::setCursorMode(CursorMode cursorMode) {
    if(_cursorMode == cursorMode)
        return;
    
    _cursorMode = cursorMode;
}

void MouseEvent::update(WindowDisplay* window, const float elapsed) {
    Input -> setMouseCursorMode(window, _cursorMode);
    
    x = getRawX(window);
    y = getRawY(window);
    
    if(eventType == "cursor") {
        execute();
    }

    if(eventType == "click") {
        if(Input -> getMouseButton(window, 1, 1)) {
            execute();
        }
    }
    
    Event::update(window, elapsed);
}
#endif