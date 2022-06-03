#pragma once

#ifndef WINDOW_INCLUDED
#define WINDOW_INCLUDED

#include "Libraries/Libs.hpp"

#include <iostream>
#include <string>

class Application;

struct WindowDisplay {
    bool fullscreen = true;
    int renderDistance = 16;
    int FOV = 90;

    void init();
    void createSize(int width, int height, bool fullscreen);
    void setTitle(std::string title);

    int getKeyboard();

    GLFWwindow* window = 0;

    int getWidth() const;
    int getHeight() const;

    private:
        friend class Application;

        int width = 1280;
        int height = 720;

        void pre_render();
    void setCallbacks(WindowDisplay* window);

    static void buffer_resize(GLFWwindow* window, int width, int height);
    static void mouse_position(GLFWwindow* window, double xPos, double yPos);
};
#endif