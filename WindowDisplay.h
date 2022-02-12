#pragma once

#ifndef WINDOW_INCLUDED
#define WINDOW_INCLUDED

#include "Libraries/Libs.hpp"

#include <iostream>
#include <string>

struct WindowDisplay {
    int width = 1280;
    int height = 720;
    bool fullscreen = true;
    int renderDistance = 16;
    int FOV = 90;

    void init();
    void createSize(int width, int height, bool fullscreen);
    void setTitle(std::string title);
    void enableCursor();
    void disableCursor();
    void pre_render();

    GLFWwindow* window = 0;
};
#endif