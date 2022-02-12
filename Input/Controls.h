#ifndef CONTROLS_INCLUDED
#define CONTROLS_INCLUDED

#include "../Libraries/Libs.hpp"
#include "../Util/FeshAxis.hpp"
#include "../WindowDisplay.cpp"
#include "Keys.hpp"

#include <iostream>
#include <map>

class Controls {
    public:
        Controls() = default;
        ~Controls() = default;

        bool GetKeyPressed(short key);
        bool GetKeyHolding(short key);
        bool GetKeyReleased(short key);

        void bindToWindow(WindowDisplay* window);

        float getMouse(FeshAxis axis);
        float getMouseRot(FeshAxis axis);

        void positionMouse();
        void resetBinds();
    private:
        WindowDisplay* daWindow;

        glm::vec2 prevMousePos;
};
#endif