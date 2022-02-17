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
    NEAREST,
    LINEAR,
    MIPMAP,
    CLAMP_TO_EDGE,
    REPEAT
};

enum TexMap {
    DIFFUSE = 0,
    SPECULAR = 1
};

class DefaultTextures {
    public:
        DefaultTextures();
        ~DefaultTextures();

        void createTexture(const TexEnum type, const TexParams params, const TexParams anti, const int sides, const TexMap map);
        void loadFile(const std::string &file);

        void Draw(GLuint VAO, GLenum primType, GLuint instances, GLsizei elements, bool drawElements, Shaders* shader);

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