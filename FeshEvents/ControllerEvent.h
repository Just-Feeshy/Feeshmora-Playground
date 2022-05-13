#pragma once

#ifndef CONTROLLER_EVENT_INCLUDED
#define CONTROLLER_EVENT_INCLUDED

#include "Event.h"

struct ControllerEvent: public Event {
    void update(WindowDisplay* window, const float elapsed) override;

    static ControllerEvent keyDown(const short key);
    static ControllerEvent keyUp(const short key);

    short getKeyID() const;

    private:
        bool keyPhase;

        short keyID;
};
#endif