#pragma once

#ifndef EVENT_TEMPLATE_INCLUDED
#define EVENT_TEMPLATE_INCLUDED

#include "../Objects/EventObject.h"
#include "../WindowDisplay.cpp"

class Application;

struct Event {
    virtual void update(WindowDisplay* window, const float elapsed) {glfwPollEvents();}

    protected:
        friend class Application;

        virtual void execute() = 0;

        Event() {};
};
#endif