#pragma once

#ifndef DEFAULT_TEXTURE_INCLUDED_CPP
#define DEFAULT_TEXTURE_INCLUDED_CPP

#include "BackendTextures.h"

BackendTextures::BackendTextures() {
    return;
}

BackendTextures::~BackendTextures() {
    /**
    if(bitmap != nullptr) {
        delete bitmap;
    }

    for(int i=0; i<textures.size(); i++) {
        glDeleteVertexArrays(1, &textures[i][0]);
    }

    textures.clear();
    */
}

void BackendTextures::loadFile(const std::string &file) {
    bitmap = new Bitmap();
    bitmap -> FlipImage(true);

    //Check for proper file.
    if(FileAssets::exist(file)) {
        int results = bitmap -> getFromFile(file.c_str());

        if(results == -1) {
            throw "Texture doesn't exist!";

            delete bitmap;
            bitmap = nullptr;
        }
    }else {
        std::cout << "Image file can't be found" << std::endl;
    }
}

void BackendTextures::createTexture(const TexEnum type, int sides, const TexMap map) {
    textures.push_back({0, map});

    GLenum target;

    switch(type) {
        case REGULAR: target = GL_TEXTURE_2D; break;
        case CUBEMAP: target = GL_TEXTURE_CUBE_MAP; break;
    }

    if(active < map) {
        active = map;
    }
    
    glGenTextures(1, &textures.back()[0]);
    glBindTexture(target, textures.back()[0]);

    if(type == CUBEMAP) {
        target = GL_TEXTURE_CUBE_MAP_POSITIVE_X;
    }

    if(map != NONE) {
        for(int i=0; i<sides; i++) {
    
            //TODO: Fix this.
            if(bitmap -> getBytes()) {
                glTexImage2D(target + (GLuint)i, 0, GL_RGBA, bitmap -> getWidth(), bitmap -> getHeight(), 0, getTexFormat(map), GL_UNSIGNED_BYTE, bitmap -> getBytes());
            }else {
                std::cout << "TEXTURE FAILED TO LOAD!" << std::endl;
            }
        }
    
        glGenerateMipmap(target);
    
        delete bitmap;
        bitmap = nullptr;
    }

    if(type == CUBEMAP) {
        target = GL_TEXTURE_CUBE_MAP;
    }

    glBindTexture(target, 0);

    texEnum = target;
}

void BackendTextures::bindTexture(Attachments attach, int section, bool bind2D, int level) {
    GLenum attachSection = attach + section;

    glBindTexture(GL_TEXTURE_2D, textures.back()[0]);

    if(bind2D) {
        glFramebufferTexture2D(GL_FRAMEBUFFER, attachSection, GL_TEXTURE_2D, textures.back()[0], level);
    }else {
        glFramebufferTexture(GL_FRAMEBUFFER, attachSection, textures.back()[0], level);
    }
}

void BackendTextures::setupParameters(const TexEnum type, const TexParams params, const TexParams min, const TexParams max) {
    GLenum target;

    switch(type) {
        case REGULAR: target = GL_TEXTURE_2D; break;
        case CUBEMAP: target = GL_TEXTURE_CUBE_MAP; break;
    }

    //Parameter Stuff. and also do some extra touches in the future.
    glTexParameterf(target, GL_TEXTURE_MIN_FILTER, min);
    glTexParameterf(target, GL_TEXTURE_MAG_FILTER, max);
    glTexParameteri(target, GL_TEXTURE_WRAP_S, params);
    glTexParameteri(target, GL_TEXTURE_WRAP_T, params);
    glTexParameteri(target, GL_TEXTURE_WRAP_R, params);
}

void BackendTextures::Draw(GLuint VAO, GLenum primType, GLuint instances, GLsizei elements, bool drawElements, Shaders* shader) {
    for(GLuint i=0; i<textures.size(); i++) {
        shader -> uniformInt("texture0", 0);
        shader -> uniformInt("texture1", 1);
        
        glActiveTexture(GL_TEXTURE0 + textures[i][1]);
        glBindTexture(texEnum, textures[i][0]);
    }

    bitmap -> Draw(VAO, primType, instances, elements, drawElements);
}

GLenum BackendTextures::getTexFormat(const TexMap map) const {
    switch(map) {
        case DIFFUSE: return GL_RGBA;
        case SPECULAR: return GL_RGBA;
        default: return GL_RGBA;
    }
}

GLenum BackendTextures::getTexEnum() const {
    return texEnum;
}

GLuint BackendTextures::getTextureByIndex(GLuint &index) const {
    return textures[index][0];
}
#endif