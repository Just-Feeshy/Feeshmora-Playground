#pragma once

#ifndef BUFFER_FUNC_INCLUDED
#define BUFFER_FUNC_INCLUDED

enum BufferFunc {
    NEVER = 0x0200,
    LESS = 0x0201,
    EQUAL = 0x0202,
    L_EQUAL = 0x0203,
    GREATER = 0x0204,
    NOT_EQUAL = 0x0205,
    G_EQUAL = 0x0206,
    ALWAYS = 0x0207
};
#endif