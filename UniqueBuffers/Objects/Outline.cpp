#pragma once

#include "Outline.h"

Outline::Outline() {
    return;
}

Outline::~Outline() {
    if(outlineShader != nullptr) {
        delete outlineShader;
    }
}

void Outline::render() {
    //outlineShader -> loadFiles(
    //    ""
    //) 
}

void Outline::draw(Shaders* shader) {
    
    
    outlineShader -> update();
}