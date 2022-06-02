#pragma once

#ifndef CONTROLLER_EVENT_CPP_INCLUDED
#define CONTROLLER_EVENT_CPP_INCLUDED

#include "ControllerEvent.h"

using namespace Feeshmora;

ControllerEvent::ControllerEvent() {
    Input = new InputBackend();
}

ControllerEvent::~ControllerEvent() {
    if(Input != nullptr) {
        delete Input;
    }

    if(keyID != nullptr) {
        delete keyID;
    }
}

short ControllerEvent::getKeyCode() const {
    return keyCode;
}

short* ControllerEvent::getKeyID() const {
    return keyID;
}

bool ControllerEvent::getKeyPhase() const {
    return keyPhase;
}

ControllerEvent* ControllerEvent::KEYDOWN(short* key) {
    ControllerEvent* event = new ControllerEvent();
    event -> keyPhase = true;
    event -> keyID = key;
    return event;
}

ControllerEvent* ControllerEvent::KEYUP(short* key) {
    ControllerEvent* event = new ControllerEvent();
    event -> keyPhase = false;
    event -> keyID = key;
    return event;
}

void ControllerEvent::execute() {
    eventOBJ -> onKeyboardEvent(this);
}

void ControllerEvent::update(WindowDisplay* window, const float elapsed) {
    int index = 0;

    while(keyID[index] != 0) {
        if(Input -> getKeyAction(window, getKeyID()[index], keyPhase)) {
            keyCode = keyID[index];
            execute();
        }

        index++;
    }
    
    Event::update(window, elapsed);
}

#endif