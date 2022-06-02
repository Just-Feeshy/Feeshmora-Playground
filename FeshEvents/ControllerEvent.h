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
    public:
        ControllerEvent();
        ~ControllerEvent();
    
        static ControllerEvent* KEYDOWN(short* key);
        static ControllerEvent* KEYUP(short* key);
    
        void update(WindowDisplay* window, const float elapsed) override;

        short getKeyCode() const;
        short* getKeyID() const;
        bool getKeyPhase() const;
    
        void execute() override;
    private:
        InputBackend* Input;

        bool keyPhase;

        short* keyID;
        short keyCode;
};
#endif