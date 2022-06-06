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

#ifndef ENGINE_ATTACHMENTS_INCLUDED
#define ENGINE_ATTACHMENTS_INCLUDED

enum Attachments {
    COLOR = 0x8CE0,
    DEPTH = 0x8D00,
    STENCIL = 0x8D20,
    DEPTH_STENCIL = 0x821A
};
#endif