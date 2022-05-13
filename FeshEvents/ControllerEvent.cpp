#pragma once

#ifndef CONTROLLER_EVENT_CPP_INCLUDED
#define CONTROLLER_EVENT_CPP_INCLUDED

#include "ControllerEvent.h"

short ControllerEvent::getKeyID() const {
    return keyID;
}

ControllerEvent ControllerEvent::keyDown(const short key) {
    ControllerEvent event;
    event.keyPhase = true;
    return event;
}

ControllerEvent ControllerEvent::keyUp(const short key) {
    ControllerEvent event;
    event.keyPhase = false;
    return event;
}

void ControllerEvent::update(WindowDisplay* window, const float elapsed) {
    
    
    Event::update(window, elapsed);
}

#endif