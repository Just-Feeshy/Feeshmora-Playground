#pragma once

#ifndef INPUT_BACKENDED_INCLUDED
#define INPUT_BACKENDED_INCLUDED

#include "../Util/FeshAxis.hpp"
#include "../Util/CursorMode.hpp"
#include "../WindowDisplay.cpp"

namespace Feeshmora {
    class InputBackend {
        public:
            bool getKeyAction(WindowDisplay* window, const short &key, const bool &phase) {
                if(phase) {
                    return (glfwGetKey(window -> window, key) >= int(phase));
                }else {
                    return (glfwGetKey(window -> window, key) == int(phase));
                }
            }
        
            double getMousePosXY(WindowDisplay* window, const FeshAxis axis) {
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
        
            void setMousePos(WindowDisplay* window, const double x, const double y) {
                glfwSetCursorPos(window -> window, x, y);
            }
        
            bool getMouseButton(WindowDisplay* window, const short &button, const short &action) {
                if(action > 1) {
                    return (glfwGetMouseButton(window -> window, button) == GLFW_PRESS || glfwGetMouseButton(window -> window, button) == GLFW_REPEAT);
                }
                
                return (glfwGetMouseButton(window -> window, button) == action);
            }
        
            void setMouseVisible(WindowDisplay* window, const bool condition) {
                if(condition)
                    glfwSetInputMode(window -> window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
                else
                    glfwSetInputMode(window -> window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
            }
        
            void setMouseCursorMode(WindowDisplay* window, CursorMode cursorMode) {
                glfwSetInputMode(window -> window, GLFW_CURSOR, cursorMode);
            }
    };
}
#endif