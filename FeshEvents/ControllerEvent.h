#pragma once

#ifndef CONTROLLER_EVENT_INCLUDED
#define CONTROLLER_EVENT_INCLUDED

#include "../Inputs/InputBackend.hpp"
#include "../Inputs/Keys.cpp"

#include "Event.h"

using namespace Feeshmora;

/**
* Made uppercase methods to signify contructors
*/
class ControllerEvent: public Event {
    ControllerEvent();
    ~ControllerEvent();

    static ControllerEvent* KEYDOWN(const short key);
    static ControllerEvent* KEYUP(const short key);

    void update(WindowDisplay* window, const float elapsed) override;

    short getKeyID() const;
    bool getKeyPhase() const;

    void execute() override;
    private:
        InputBackend* Input;

        bool keyPhase;

        short keyID;
};
#endif