#pragma once

#ifndef EVENT_OBJECT_INCLUDED
#define EVENT_OBJECT_INCLUDED

struct Event;

/**
* This is a interface.. lol
*/
class EventObject {
    public:
        EventObject() = default;
        ~EventObject() = default;

        virtual void onKeyboardEvent(Event* event) = 0;
        virtual void onMouseEvent(Event* event) = 0;
    private:
        float mouse_sensivity = 0.5;
};
#endif