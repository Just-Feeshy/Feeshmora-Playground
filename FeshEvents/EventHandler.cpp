#pragma once

#include "EventHandler.h"

template<typename T> EventHandler<T>::EventHandler() {
    event = std::make_unique<T>();
    event -> getEvent();
}