#include "TriangleState.h"

#include <math.h>
#include <iostream>
#include <stdio.h>

float i = 0;

/**
* This is literally a testing state algorithm to make
* a `Hello Triangle` in a very object orientated way.
*/

void TriangleState::onCreate() {
    //Hello Triangle Here!

    GLuint indices[] = {
        0, 1, 2,
        2, 3, 4
    };

    triangleShaders = std::make_unique<Shaders>(
        "Shaders/BasicTriangle.glsl",
        "Shaders/BasicTriangle.fs"  
    );

    triangleShaders -> useShaderProgram();
    
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    triangleTextures = std::make_unique<FirstTextures>();

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices::triangleVertices), Vertices::triangleVertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    //glBindBuffer(GL_ARRAY_BUFFER, 0);
    //glBindVertexArray(0);
    //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    triangleTextures -> fromFile(
        "Assets/images/feesh/FeshGL.png"
    );

    triangleShaders -> useShaderProgram();
    //triangleShaders -> uniformInt("texture0", 0);
}

TriangleState::~TriangleState() {
    glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);

    clear();
}

void TriangleState::update(float elapsed) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    triangleShaders -> useShaderProgram();
    //triangleShaders -> uniformFloat("anim", i);

    triangleTextures -> bind();
    triangleTextures -> Draw(VAO, GL_TRIANGLES, 1, 6, true);

    i += 0.04;
}