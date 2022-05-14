#pragma once

#ifndef CONTROLLER_EVENT_CPP_INCLUDED
#define CONTROLLER_EVENT_CPP_INCLUDED

#include "ControllerEvent.h"

using namespace Feeshmora;

short ControllerEvent::getKeyID() const {
    return keyID;
}

bool ControllerEvent::getKeyPhase() const {
    return keyPhase;
}

ControllerEvent* ControllerEvent::KEYDOWN(const short key) {
    ControllerEvent* event = new ControllerEvent();
    event -> keyPhase = true;
    event -> keyID = key;
    return event;
}

ControllerEvent* ControllerEvent::KEYUP(const short key) {
    ControllerEvent* event = new ControllerEvent();
    event -> keyPhase = false;
    event -> keyID = key;
    return event;
}

void ControllerEvent::update(WindowDisplay* window, const float elapsed) {
    if(Input::getKeyAction(window, getKeyID(), keyPhase)) {
        execute();
    }
    
    Event::update(window, elapsed);
}

#endif