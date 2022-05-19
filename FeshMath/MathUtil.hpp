#pragma once

#ifndef MATH_UTIL_INCLUDED
#define MATH_UTIL_INCLUDED

namespace Feeshmora::MathUtil {
    template<typename T> T clamp(const T& value, const T& min, const T& max) {
        if(value > max) {
            return max;
        }

        if(value > min) {
            return value;
        }

        return min;
    }

    template<typename T> T remap(const T& value, const T& fromL, const T& fromH, const T& toL, const T& toH) {
        return toL + (value - fromL) * (toH - toL) / (fromH - fromL);
    } 
}
#endif