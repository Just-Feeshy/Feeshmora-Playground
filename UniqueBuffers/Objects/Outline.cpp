#pragma once

#include "Outline.h"

Outline::Outline() {
    Shaders outline;
    
    shaderGroup.push_back(outline);
}

Outline::~Outline() {
    if(shaderGroup.size() > 0) {
        shaderGroup.clear();
    }
}

void Outline::render() {
    shaderGroup[0].loadFiles(
        "Shaders/OutlineShaders.glsl",
        "Shaders/OutlineShaders.fs"
    );
}

void Outline::draw(Shaders* shader) {
    if(shader -> getUniformValues() -> find("cameraMatrix") != shader -> getUniformValues() -> end()) {
        shaderGroup[0].uniformMat4("cameraMatrix", shader -> getUniformValues() -> operator[]("cameraMatrix"));
    }
}

void Outline::update() {
    if(shaderGroup.size() > 0) {
        std::for_each(shaderGroup.begin(), shaderGroup.end(), [](Shaders &shader) {
            shader.update();
        });
    }
}

void Outline::draw(Shaders* shader, const int index) {
    return;
}