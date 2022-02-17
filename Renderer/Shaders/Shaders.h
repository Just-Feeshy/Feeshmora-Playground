#pragma once

#ifndef FIRST_SHADER_INCLUDED
#define FIRST_SHADER_INCLUDED

#include "../../Util/FileAssets.hpp"
#include "../Render.hpp"

#include <string>
#include <iostream>

enum ShaderType {
    VERTICES,
    FRAGMENT
};

class Shaders: public Render {
    public:
        Shaders() = default;
        
        Shaders(std::string vrtxShaders, std::string fagShaders);
        ~Shaders() = default;

        GLuint link(GLuint vrtxID, GLuint fragID);
        GLuint compileFile(const char* file, GLenum shader);

        void loadFromString(const char* source, const ShaderType fv);

        void loadFiles(std::string vrtxShaders, std::string fagShaders);

        bool loadedShaders() const;
    private:
        bool loaded = false;
};
#endif