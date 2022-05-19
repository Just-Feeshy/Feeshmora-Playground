#pragma once

#ifndef EVENT_TEMPLATE_INCLUDED
#define EVENT_TEMPLATE_INCLUDED

#include "../Objects/EventObject.h"
#include "../WindowDisplay.cpp"

#include <memory>

class Application;

class Event {
    public:
        virtual void update(WindowDisplay* window, const float elapsed) {glfwPollEvents();}
    
        protected:
            Event() {};
    
            friend class Application;
    
            virtual void execute() = 0;
    
            EventObject* eventOBJ;
};
#endif