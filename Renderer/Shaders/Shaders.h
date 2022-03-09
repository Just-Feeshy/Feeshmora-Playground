#pragma once

#ifndef FIRST_SHADER_INCLUDED
#define FIRST_SHADER_INCLUDED

#include "../Fragments/ShaderFragments.cpp"
#include "../../Util/FileAssets.hpp"
#include "../Render.hpp"

#include <string>
#include <iostream>

enum ShaderType {
    VERTICES,
    FRAGMENT,
    BOTH
};

class Shaders: public Render {
    public:
        Shaders() = default;
        
        Shaders(std::string vrtxShaders, std::string fagShaders);
        ~Shaders();

        GLuint link(GLuint vrtxID, GLuint fragID);
        GLuint compileFile(const char* file, GLenum shader);

        void loadFromString(const char* source, const ShaderType fv);

        void loadFiles(const std::string vrtxShaders, const std::string fagShaders);

        void loadFiles(const std::string vrtxShaders, const std::string fagShaders, const std::string extraString, const ShaderType fv);

        bool loadedShaders() const;
    private:
        bool loaded = false;
};
#endif