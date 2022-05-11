#pragma once

#ifndef BASICSTATE_INCLUDED
#define BASICSTATE_INCLUDED

#include "../WindowDisplay.cpp"

class BasicStates {
    public:
        BasicStates() = default;

        virtual ~BasicStates() = default;

        virtual void onCreate() = 0;
        virtual void update(float elapsed) = 0;
    protected:
        friend class Application;

        virtual void configWithWindow(WindowDisplay* window) = 0;
};
#endif