#pragma once

#ifndef EVENT_TEMPLATE_INCLUDED
#define EVENT_TEMPLATE_INCLUDED

class Application;

struct Event {
    virtual void getEvent();

    protected:
        void execute() {
            (*callback)(); 
        }
    private:
        friend class Application;

        void (*callback)();
};
#endif