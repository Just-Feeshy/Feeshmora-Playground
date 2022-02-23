#pragma once

#include "Shaders.h"

Shaders::Shaders(std::string vrtxShaders, std::string fagShaders) {
    loadFiles(vrtxShaders, fagShaders);
}

GLuint Shaders::link(GLuint vrtxID, GLuint fragID) {
    auto shaders = glCreateProgram();

    if(vrtxID != 0) {
        glAttachShader(shaders, vrtxID);
    }

    if(fragID != 0) {
        glAttachShader(shaders, fragID);
    }

    glLinkProgram(shaders);

    return shaders;
}

void Shaders::loadFiles(const std::string vrtxShaders, const std::string fagShaders) {
    std::string vrtxSource = ShaderFragments::getVersion() + FileAssets::getTXT(vrtxShaders);
    std::string fagSource = ShaderFragments::getVersion() + FileAssets::getTXT(fagShaders);

    GLuint vrtxID = compileFile(vrtxSource.c_str(), GL_VERTEX_SHADER);
    GLuint fragID = compileFile(fagSource.c_str(), GL_FRAGMENT_SHADER);

    GLuint shader = link(vrtxID, fragID);

    glDeleteShader(vrtxID);
    glDeleteShader(fragID);

    glUseProgram(shader);
    shaderProgram = shader;
    loaded = true;
}

void Shaders::loadFiles(const std::string vrtxShaders, const std::string fagShaders, const std::string extraString, const ShaderType fv) {
    std::string vsExtra;
    std::string fsExtra;

    if(fv == VERTICES) {
        vsExtra = extraString;
    }else if(fv == FRAGMENT) {
        fsExtra = extraString;
    }else {
        fsExtra = extraString;
        vsExtra = extraString;
    }
    
    std::string vrtxSource = ShaderFragments::getVersion() + vsExtra + FileAssets::getTXT(vrtxShaders);
    std::string fagSource = ShaderFragments::getVersion() + fsExtra + FileAssets::getTXT(fagShaders);

    GLuint vrtxID = compileFile(vrtxSource.c_str(), GL_VERTEX_SHADER);
    GLuint fragID = compileFile(fagSource.c_str(), GL_FRAGMENT_SHADER);

    GLuint shader = link(vrtxID, fragID);

    glDeleteShader(vrtxID);
    glDeleteShader(fragID);

    glUseProgram(shader);
    shaderProgram = shader;
    loaded = true;
}

void Shaders::loadFromString(const char* source, const ShaderType fv) {
    GLuint id = compileFile(source, GL_VERTEX_SHADER);
    
    GLuint shader;

    if(fv == VERTICES) {
        shader = link(id, 0);
    }

    if(fv == FRAGMENT) {
        shader = link(0, id);
    }

    glDeleteShader(id);

    glUseProgram(shader);
    shaderProgram = shader;
    loaded = true;
}

bool Shaders::loadedShaders() const {
    return loaded;
}

GLuint Shaders::compileFile(const char* file, GLenum shader) {
    auto shaderTypeID = glCreateShader(shader);
    glShaderSource(shaderTypeID, 1, &file, nullptr);
    glCompileShader(shaderTypeID);

    return shaderTypeID;
}