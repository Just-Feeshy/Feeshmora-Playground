#pragma once

#ifndef CONTROLLER_EVENT_INCLUDED
#define CONTROLLER_EVENT_INCLUDED

#include "../Inputs/InputBackend.cpp"
#include "../Inputs/Keys.cpp"

#include "Event.h"

/**
* Made uppercase methods to signify contructors
*/
struct ControllerEvent: public Event {
    void update(WindowDisplay* window, const float elapsed) override;

    static ControllerEvent KEYDOWN(const short key);
    static ControllerEvent KEYUP(const short key);

    short getKeyID() const;
    bool getKeyPhase() const;
    private:
        ControllerEvent() {};

        bool keyPhase;

        short keyID;
};
#endif