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
    static ControllerEvent* KEYDOWN(const short key);
    static ControllerEvent* KEYUP(const short key);

    void update(WindowDisplay* window, const float elapsed) override;

    short getKeyID() const;
    bool getKeyPhase() const;

    void execute() override {}
    private:
        //ControllerEvent() {};

        bool keyPhase;

        short keyID;
};
#endif