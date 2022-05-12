#pragma once

#ifndef EVENT_TEMPLATE_INCLUDED
#define EVENT_TEMPLATE_INCLUDED

class Application;

struct Event {
    virtual void update(float elapsed);

    protected:
        void execute() {
            (*callback)(this); 
        }
    private:
        friend class Application;

        void (*callback)(Event*);
};
#endif