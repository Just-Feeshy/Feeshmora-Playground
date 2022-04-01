#pragma once

#ifndef FACE_CULL_INCLUDED
#define FACE_CULL_INCLUDED

enum FaceCull {
    CULL_FRONT = 0x0404,
    CULL_BACK = 0x0405,
    CULL_FRONT_BACK = 0x0408,
    CULL_NONE = 0
};
#endif

#ifndef ALPHA_BLEND_INCLUDED
#define ALPHA_BLEND_INCLUDED

/**
* Not going to put the whole thing in.
*/
enum Blend {
    BLEND_SOURCE_COLOR = 0x0300,
    BLEND_ONE_MINUS_SOURCE_COLOR = 0x0301,
    BLEND_SOURCE_ALPHA = 0x0302,
    BLEND_ONE_MINUS_SOURCE_ALPHA = 0x0303,
    BLEND_NONE = 0
};
#endif