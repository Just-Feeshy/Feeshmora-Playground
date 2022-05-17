#pragma once

#ifndef CURSOR_STATUS_CPP_INCLUDED
#define CURSOR_STATUS_CPP_INCLUDED

#include "CursorStatus.h"

using namespace Feeshmora;

bool CursorStatus::_lockedState = false;
bool CursorStatus::_visible = true;

void CursorStatus::lockCursor(const bool mouse) {
    if(_lockedState == mouse)
        return;
    
    _lockedState = mouse;
    setVisible(!_lockedState);
}

void CursorStatus::setVisible(const bool mouse) {
    if(_visible == mouse)
        return;

    _visible = mouse;
    Input::setMouseVisible(Application::daWindow, _visible);
}

void CursorStatus::update() {
    if(_lockedState) {
        Input::setMousePos(Application::daWindow, (double)Application::daWindow -> width / 2, (double)Application::daWindow -> height / 2);
    }
}
#endif