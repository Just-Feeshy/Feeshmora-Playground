#pragma once

#ifndef INPUT_BACKENDED_INCLUDED
#define INPUT_BACKENDED_INCLUDED

#include "../Util/FeshAxis.hpp"
#include "../WindowDisplay.cpp"

namespace Feeshmora::Input {
    bool getKeyAction(WindowDisplay* window, const short key, const bool phase) {
        if(phase) {
            return (glfwGetKey(window -> window, key) >= int(phase));
        }else {
            return (glfwGetKey(window -> window, key) == int(phase));
        }
    }

    double getMousePosXY(WindowDisplay* window, FeshAxis axis) {
        double pos;
        
        switch(axis) {
            case X:
                glfwGetCursorPos(window -> window, &pos, 0);
                return pos;
            case Y:
                glfwGetCursorPos(window -> window, 0, &pos);
                return pos;
            default:
                throw "Unexpected axis!";
                return -1;
        }
    }

    void setMousePos(WindowDisplay* window, double x, double y) {
        glfwSetCursorPos(window -> window, x, y);
    }
}
#endif