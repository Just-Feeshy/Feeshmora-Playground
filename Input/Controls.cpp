#include "Controls.h"

Controls::~Controls() {
    return;
}

bool Controls::GetKeyPressed(short keys) {
    int keyResult = glfwGetKey(daWindow -> window, (int)keys);
    return (keyResult == GLFW_PRESS);
}

bool Controls::GetKeyHolding(short keys) {
    int keyResult = glfwGetKey(daWindow -> window, (int)keys);

    return (keyResult == GLFW_PRESS || keyResult == GLFW_REPEAT);
}

bool Controls::GetKeyReleased(short keys) {
    int keyResult = glfwGetKey(daWindow -> window, (int)keys);

    return (keyResult == GLFW_RELEASE);
}

float Controls::getMouse(FeshAxis axis) {
    double x, y;
    glfwGetCursorPos(daWindow -> window, &x, &y);

    if(axis == Y) {
        prevMousePos.y = (float)y;
        return prevMousePos.y;
    }else {
        prevMousePos.x = (float)x;
        return prevMousePos.x;
    }
}

float Controls::getMouseRot(FeshAxis axis) {
    if(axis == Y) {
        return (float)(getMouse(axis) - (daWindow -> height / 2)) / daWindow -> height;
    }else {
        return (float)(getMouse(axis) - (daWindow -> width / 2)) / daWindow -> width;
    }
}

void Controls::bindToWindow(WindowDisplay* window) {
    daWindow = window;
}

void positionMouse() {
    //if(getMouse(X) == )
}