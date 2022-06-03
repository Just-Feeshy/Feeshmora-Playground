#pragma once

#ifndef WINDOW_INCLUDED
#define WINDOW_INCLUDED

#include "Libraries/Libs.hpp"

#include <iostream>
#include <string>

struct WindowDisplay {
    bool fullscreen = true;
    int renderDistance = 16;
    int FOV = 90;

    void init();
    void createSize(int width, int height, bool fullscreen);
    void setTitle(std::string title);
    void pre_render();

    int getKeyboard();

    GLFWwindow* window = 0;

    int getWidth() const;
    int getHeight() const;

    private:
        int width = 1280;
        int height = 720;
};
#endif