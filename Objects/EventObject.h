#pragma once

#ifndef EVENT_OBJECT_INCLUDED
#define EVENT_OBJECT_INCLUDED

/**
* This is a interface.. lol
*/
class EventObject {
    public:
        EventObject() = default;
        ~EventObject() = default;

        virtual void onKeyboardEvent() = 0;
        virtual void onMouseEvent() = 0;
};
#endif