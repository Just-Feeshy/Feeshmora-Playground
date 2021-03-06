#pragma once

#ifndef DEFAULT_TEXTURE_INCLUDED
#define DEFAULT_TEXTURE_INCLUDED

#include "../../Util/FileAssets.hpp"
#include "../../Renderer/Shaders/Shaders.cpp"
#include "../../FeshMath/MathUtil.hpp"
#include "../Bitmap.cpp"

#include <string>
#include <vector>
#include <array>

enum TexEnum {
    REGULAR,
    CUBEMAP
};

enum TexParams {
    NO_PARAMS = 0,
    NEAREST = 0x2600,
    LINEAR = 0x2601,
    MIPMAP = 0x2702,
    CLAMP_TO_EDGE = 0x812F,
    REPEAT = 0x2901
};

enum TexMap {
    NO_MAP = 0,
    DIFFUSE = 1,
    SPECULAR = 2
};

class BackendTextures {
    public:
        BackendTextures();
        ~BackendTextures();

        void createTexture(const TexEnum type, const int sides, const TexMap map);
        void setupParameters(const TexEnum type, const TexParams params, const TexParams min, const TexParams max);
        void loadFile(const std::string &file);

        void Draw(GLuint VAO, GLenum primType, GLuint instances, GLsizei elements, bool drawElements, Shaders* shader);

        void bindTexture(Attachments attach, int section, bool bind2D, int level);

        GLenum getTexFormat(const TexMap map) const;

        GLenum getTexEnum() const;
        GLuint getTextureByIndex(GLuint &index) const;

        void setBitmap(Bitmap* bitmap);
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