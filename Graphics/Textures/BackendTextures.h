#pragma once

#ifndef DEFAULT_TEXTURE_INCLUDED
#define DEFAULT_TEXTURE_INCLUDED

#include "../../Util/FileAssets.hpp"
#include "../../Renderer/Shaders/Shaders.cpp"
#include "../Bitmap.cpp"

#include <string>
#include <vector>
#include <array>

enum TexEnum {
    REGULAR,
    CUBEMAP
};

enum TexParams {
    NEAREST = GL_NEAREST,
    LINEAR = GL_LINEAR,
    MIPMAP = GL_NEAREST_MIPMAP_LINEAR,
    CLAMP_TO_EDGE = GL_CLAMP_TO_EDGE,
    REPEAT = GL_REPEAT
};

enum TexMap {
    DIFFUSE = 0,
    SPECULAR = 1
};

class BackendTextures {
    public:
        BackendTextures();
        ~BackendTextures();

        void createTexture(const TexEnum type, const int sides, const TexMap map);
        void setupParameters(const TexEnum type, const TexParams params, const TexParams min, const TexParams max);
        void loadFile(const std::string &file);

        void Draw(GLuint VAO, GLenum primType, GLuint instances, GLsizei elements, bool drawElements, Shaders* shader);

        void bindTexture(GLuint textureBuffer, Attachments attach, int section, bool bind2D, int level);

        GLenum getTexFormat(const TexMap map) const;

        GLenum getTexEnum() const;
        GLuint getTextureByIndex(GLuint &index) const;
    private:
        Bitmap* bitmap;

        std::string path;

        GLenum texEnum;
        //GLuint texture;

        std::vector<std::array<GLuint, 2>> textures;

        GLuint active;

        bool test;
};
#endif