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
    StencilBuffers::setStencilFunc(NOT_EQUAL, 1, 0xFF);
    StencilBuffers::setStencilMask(0x00);
    StencilBuffers::enableDepthTest(false);

    shaderGroup[0].uniformMat4("pViewMatrix", shader -> getUniformValues() -> operator[]("pViewMatrix"));
    shaderGroup[0].uniformMat4("modelMatrix", shader -> getUniformValues() -> operator[]("modelMatrix"));

    StencilBuffers::setStencilMask(0xFF);
    StencilBuffers::setStencilFunc(ALWAYS, 0, 0xFF);
    StencilBuffers::enableDepthTest(true);
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