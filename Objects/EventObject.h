#pragma once

#ifndef EVENT_OBJECT_INCLUDED
#define EVENT_OBJECT_INCLUDED

/*List of events*/
struct ControllerEvent;
struct MouseEvent;


/**
* This is a interface.. lol
*/
class EventObject {
    public:
        EventObject() = default;
        ~EventObject() = default;

        virtual void onKeyboardEvent(ControllerEvent* event) = 0;
        virtual void onMouseEvent(MouseEvent* event) = 0;
    private:
        float mouse_sensivity = 0.5;
};
#endif