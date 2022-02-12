#pragma once

#ifndef BITMAPCACHE_INCLUDED
#define BITMAPCACHE_INCLUDED

#include "../Renderer/Render.hpp"
#include "../Libraries/Libs.hpp"

#include <stdexcept>
#include <iostream>
#include <string>

/**
* Since this was made in repl.it, I couldn't add much
* to this class. Like a cache method.
*/
class Bitmap {
    public:
        Bitmap() = default;
        ~Bitmap();

        GLint getWidth();
        GLint getHeight();

        void FlipImage(bool flip);
        int getFromFile(std::string file);
        unsigned char* getBytes();

        void Draw(GLuint VAO, GLenum primType, GLuint instances, GLsizei elements, bool drawElements);
    private:
        unsigned char* pixels = 0;

        GLint width = 0;
        GLint height = 0;

        GLint comps = 0;
};
#endif