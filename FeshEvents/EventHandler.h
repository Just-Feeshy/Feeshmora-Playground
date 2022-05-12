#pragma once

#ifndef EVENT_HANDLER_INCLUDED
#define EVENT_HANDLER_INCLUDED

#include "Event.h"

#include <memory>

template<typename T> class EventHandler {
    public:
        EventHandler();

    private:
        std::unique_ptr<T> event;
};
#endif