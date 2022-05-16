#pragma once

#ifndef EVENT_TEMPLATE_INCLUDED
#define EVENT_TEMPLATE_INCLUDED

#include "../WindowDisplay.cpp"

struct Event {
    virtual void update(WindowDisplay* window, const float elapsed) {glfwPollEvents();}

    protected:
        Event() {};

        void execute() {
            
        }
};
#endif