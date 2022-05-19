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

    template<typename T> T remap(const T& value, const T& iL, const T& iH, const T& oL, const T& oH) {
        return oL + (value - iL) * (oH - oL) / (iH - iL);
    } 
}
#endif
