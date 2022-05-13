#pragma once

#ifndef CONTROLLER_EVENT_CPP_INCLUDED
#define CONTROLLER_EVENT_CPP_INCLUDED

#include "ControllerEvent.h"

short ControllerEvent::getKeyID() const {
    return keyID;
}

ControllerEvent ControllerEvent::keyDown() {
    ControllerEvent event;
    event.keyPhase = true;
    return event;
}

ControllerEvent ControllerEvent::keyUp() {
    ControllerEvent event;
    event.keyPhase = false;
    return event;
}

void ControllerEvent::update(WindowDisplay* window, float elapsed) {
    
}
#endif