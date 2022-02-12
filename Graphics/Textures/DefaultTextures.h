#ifndef DEFAULT_TEXTURE_INCLUDED
#define DEFAULT_TEXTURE_INCLUDED

#include "../../Util/FileAssets.hpp"
#include "../Bitmap.cpp"

#include <string>

enum TexEnum {
    REGULAR,
    CUBEMAP
};

enum TexParams {
    NEAREST,
    LINEAR,
    MIPMAP,
    CLAMP_TO_EDGE,
    REPEAT
};

class DefaultTextures {
    public:
        DefaultTextures();
        ~DefaultTextures();

        void createTexture(const TexEnum type, const TexParams params, const TexParams anti, const int sides);
        void loadFile(const std::string &file);

        void Draw(GLuint VAO, GLenum primType, GLuint instances, GLsizei elements, bool drawElements);

        //static void Active(int index);
    private:
        GLenum texEnum;
        GLuint texture;
        
        Bitmap* bitmap;

        std::string path;
};
#endif