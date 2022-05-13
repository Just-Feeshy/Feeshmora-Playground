#pragma once

#ifndef CONTROLLER_EVENT_INCLUDED
#define CONTROLLER_EVENT_INCLUDED

#include "Event.h"

struct ControllerEvent: public Event {
    virtual ~ControllerEvent() {}

    void update(WindowDisplay* window, float elapsed) override;

    static ControllerEvent keyDown();
    static ControllerEvent keyUp();

    short getKeyID() const;

    private:
        bool keyPhase;

        short keyID;
};
#endif