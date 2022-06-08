#pragma once

#ifndef MATH_UTIL_INCLUDED
#define MATH_UTIL_INCLUDED

namespace Feeshmora::MathUtil {
    template <typename T> const T max(const T& val1, const T& max) {
            return val1 >= max ? val1 : max;
        }

    template <typename T> const T min(const T& val1, const T& min) {
        return val1 <= min ? val1 : min;
    }

    template<typename T, typename T2> T lerp(const T& from, const T& to, const T2& at) {
        return (T)(from * ((U)(1) - at) + to * at);
    }
    
    template<typename T> T clamp(const T& value, const T& min, const T& max) {
        if(value >= max) {
            return max;
        }

        if(value >= min) {
            return value;
        }

        return min;
    }

    template<typename T> T remap(const T& value, const T& iL, const T& iH, const T& oL, const T& oH) {
        return oL + (value - iL) * (oH - oL) / (iH - iL);
    } 
}
#endif
