#pragma once

#ifndef INPUT_BACKENDED_INCLUDED
#define INPUT_BACKENDED_INCLUDED

#include "../WindowDisplay.cpp"

namespace Feeshmora::Input {
        bool getKeyAction(WindowDisplay* window, const short key, const bool phrase) {
            if(phrase) {
                return (glfwGetKey(window -> window, key) >= int(phrase));
            }else {
                return (glfwGetKey(window -> window, key) == int(phrase));
            }
        }
}
#endif