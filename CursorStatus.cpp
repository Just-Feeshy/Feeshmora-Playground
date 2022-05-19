#pragma once

#ifndef CURSOR_STATUS_CPP_INCLUDED
#define CURSOR_STATUS_CPP_INCLUDED

#include "CursorStatus.h"

bool CursorStatus::_lockedState = false;
bool CursorStatus::_visible = true;

void CursorStatus::lockCursor(const bool mouse) {
    if(_lockedState == mouse)
        return;
    
    _lockedState = mouse;
}

void CursorStatus::setVisible(const bool mouse) {
    if(_visible == mouse)
        return;

    _visible = mouse;
}
#endif