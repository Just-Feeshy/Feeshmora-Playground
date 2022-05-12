#ifndef CONTROLS_INCLUDED
#define CONTROLS_INCLUDED

#include "../Libraries/Libs.hpp"
#include "../Util/FeshAxis.hpp"
#include "../WindowDisplay.cpp"
#include "Keys.hpp"

#include <iostream>
#include <functional>
#include <vector>

class Controls {
    public:
        Controls() = default;
        ~Controls();

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