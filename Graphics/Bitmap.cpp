#pragma once

#include "Bitmap.h"

Bitmap::~Bitmap() {
    if(pixels != nullptr) {
        stbi_image_free(pixels);
    }
}

GLint Bitmap::getWidth() {
    return width;
}

GLint Bitmap::getHeight() {
    return height;
}

GLint Bitmap::getFromFile(std::string file) {
    pixels = stbi_load(file.c_str(), &width, &height, &comps, 4);

    return comps;
}

void Bitmap::FlipImage(bool flip) {
    stbi_set_flip_vertically_on_load(flip);
}

unsigned char* Bitmap::getBytes() {
    return pixels;
}

void Bitmap::Draw(GLuint VAO, GLenum primType, GLuint instances, GLsizei elements, bool drawElements) {
    if (drawElements && instances == 0)
        return;

    glBindVertexArray(VAO);

    if(drawElements) {
        if (instances == 1) {
            glDrawElements(primType, elements, GL_UNSIGNED_INT, 0);
        }else {
            glDrawElementsInstanced(primType, elements, GL_UNSIGNED_INT, 0, instances);
        }
    }else {
        glDrawArrays(primType, 0, instances);
    }
}