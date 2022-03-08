#pragma once

#ifndef STENCIL_FAIL_INCLUDED
#define STENCIL_FAIL_INCLUDED

enum StencilFail {
    ZERO = 0,
    KEEP = 0x1E00,
    REPLACE = 0x1E01,
    INCREASE = 0x1E02,
    DECREASE = 0x1E03,
    INVERT = 0x150A
};
#endif