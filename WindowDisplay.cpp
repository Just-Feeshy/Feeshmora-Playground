#pragma once

#include "WindowDisplay.h"

void WindowDisplay::init() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
}

void WindowDisplay::createSize(int width, int height, bool fullscreen) {
    this -> width = width;
    this -> height = height;
    this -> fullscreen = fullscreen;

    if(window != 0) {
        glfwSetWindowSize(
            window, 
            this -> width,
            this -> height
        );
    }else {
        window = glfwCreateWindow(
            this -> width,
            this -> height,
            "Spoopy Game",
            nullptr, nullptr
        );

        glfwMakeContextCurrent(window);
    }
}

void WindowDisplay::setTitle(std::string title) {
    char* aTitle = const_cast<char*>(title.c_str());
    
    if(window != 0) {
        glfwSetWindowTitle(
            window, 
            aTitle
        );
    }else {
        window = glfwCreateWindow(
            this -> width,
            this -> height,
            aTitle, nullptr,
            nullptr
        );

        glfwMakeContextCurrent(window);
        glfwSwapInterval(1);
    }

    aTitle = nullptr;
    delete aTitle;
}

void WindowDisplay::pre_render() {
    glfwSwapInterval(1);
    
    gladLoadGL();
    glClearColor(0.02f, 0.02f, 0.02f, 0.02f);
    glClear(GL_COLOR_BUFFER_BIT);
    glViewport(0, 0, width, height);
    glfwSwapBuffers(window);
}

void WindowDisplay::setCallbacks(WindowDisplay* window) {
    glfwSetFramebufferSizeCallback(window -> window, window -> buffer_resize);
    //glfwSetCursorPosCallback(window -> window, )
}

void WindowDisplay::buffer_resize(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

void WindowDisplay::mouse_position(GLFWwindow* window, double xPos, double yPos) {
    return;
}

int WindowDisplay::getWidth() const {
    return width;
}

int WindowDisplay::getHeight() const {
    return height;
}