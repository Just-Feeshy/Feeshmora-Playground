#pragma once

#include "Application.h"

vector<Event> Application::events;

Application::Application(WindowDisplay &window) : daWindow(&window) {
    daWindow -> pre_render();
}

template<typename T, typename...obj> void Application::switchState(obj&&...args) {
  destroyState();
  _states.push_back(make_unique<T>(forward<obj>(args)...));

  //Auto keyword is good.
  auto &daState = _states.back();
  daState -> configWithWindow(daWindow);
  daState -> onCreate();
}

template<class T> void Application::addEvent(T event, void (*call)(T)) {
    events.push_back(event);
}

void Application::clearEvents() {
    events.clear();
}

void Application::updateEvents(float elapsed) {
    int index = 0;
    
    while(index < events.size()) {
        events[index].update(daWindow, elapsed);
        
        index++;
    }
}

void Application::update() {
    if(fps.getFramerate() >= 30) {
        auto &state = *_states.back();
        state.update(fps.getDeltaTime());
        updateEvents(fps.getDeltaTime());
        glfwSwapBuffers(daWindow -> window);

        glfwPollEvents();
    }

    fps.caculateFPS();
}

void Application::close() {
    events.clear();
    destroyState();

    glfwSetWindowShouldClose(daWindow -> window, GLFW_TRUE);

    glfwDestroyWindow(daWindow -> window);
    glfwTerminate();

    daWindow = 0;
    delete daWindow;
}

void Application::destroyState() {
    if(_states.size() > 0) {
        _states.pop_back();
    }
}

/**
* Very basic way of making this, but efficient.
*/
bool Application::isOpen() {
    if(daWindow != 0 && daWindow -> window != 0) {
        if(!glfwWindowShouldClose(daWindow -> window))
            return true;
        else
            return false;
    }

    return false;
}