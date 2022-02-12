#ifndef FIRST_TEXTURE_INCLUDED
#define FIRST_TEXTURE_INCLUDED

#include "../../Util/FileAssets.hpp"
#include "../Bitmap.cpp"

/**
* Very basic texture class.
*/
class FirstTextures {
    public:
        FirstTextures() = default;
        FirstTextures(const std::string &file);
        ~FirstTextures();

        void fromFile(const std::string &file);
        void bind();

        void Draw(GLuint VAO, GLenum primType, GLuint instances, GLsizei elements, bool drawElements);
    private:
        Bitmap* bitmap;

        GLuint texture = 0;

        int results = 0;
};
#endif