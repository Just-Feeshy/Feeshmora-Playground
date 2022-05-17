#pragma once

#ifndef CURSOR_STATUS_INCLUDED
#define CURSOR_STATUS_INCLUDED

#include "Inputs/InputBackend.cpp"
#include "Application.cpp"

struct CursorStatus {
    public:
        static void lockCursor(const bool mouse);
        static void setVisible(const bool mouse);
    private:
        friend class Application;

        static void update();

        static bool _lockedState;
        static bool _visible;
};
#endif