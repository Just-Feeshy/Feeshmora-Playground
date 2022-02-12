#include "DefaultTextures.h"

DefaultTextures::DefaultTextures() {
    return;
}

DefaultTextures::~DefaultTextures() {
    if(bitmap != nullptr) {
        delete bitmap;
    }

    glDeleteVertexArrays(1, &texture);
}

void DefaultTextures::loadFile(const std::string &file) {
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

void DefaultTextures::createTexture(const TexEnum type, const TexParams params, const TexParams anti, int sides) {
    GLuint texture;
    GLenum target;

    switch(type) {
        case REGULAR: target = GL_TEXTURE_2D; break;
        case CUBEMAP: target = GL_TEXTURE_CUBE_MAP; break;
    }

    glGenTextures(1, &texture);
    glBindTexture(target, texture);

    if(type == CUBEMAP) {
        target = GL_TEXTURE_CUBE_MAP_POSITIVE_X;
    }

    for(int i=0; i<sides; i++) {

        //TODO: Fix this.
        if(bitmap -> getBytes()) {
            glTexImage2D(target + (GLuint)i, 0, GL_RGBA, bitmap -> getWidth(), bitmap -> getHeight(), 0, GL_RGBA, GL_UNSIGNED_BYTE, bitmap -> getBytes());
        }else {
            std::cout << "TEXTURE FAILED TO LOAD!" << std::endl;
        }
    }

    glGenerateMipmap(target);

    delete bitmap;
    bitmap = nullptr;

    if(type == CUBEMAP) {
        target = GL_TEXTURE_CUBE_MAP;
    }

    GLfloat p;
    GLenum ant;

    switch(params) {
        case REPEAT: p = GL_REPEAT; break;
        default: p = GL_CLAMP_TO_EDGE; break;
    }

    switch(ant) {
        case LINEAR: ant = GL_LINEAR; break;
        case MIPMAP: ant = GL_NEAREST_MIPMAP_LINEAR; break;
        default: ant = GL_NEAREST; break;
    }

    //Parameter Stuff. and also do some extra touches in the future.
    glTexParameterf(target, GL_TEXTURE_MIN_FILTER, ant);
    glTexParameterf(target, GL_TEXTURE_MAG_FILTER, GL_NEAREST_MIPMAP_LINEAR);
    glTexParameteri(target, GL_TEXTURE_WRAP_S, params);
    glTexParameteri(target, GL_TEXTURE_WRAP_T, params);
    glTexParameteri(target, GL_TEXTURE_WRAP_R, params);

    /**
    if(type == REGULAR) {
        for(int i=0; i<sides; i++) {
            glTexImage2D(target, 0, GL_RGBA, 16, 16, 0, GL_RGBA, GL_FLOAT, NULL);
        }
    }
    **/

    glBindTexture(target, 0);

    texEnum = target;
    this -> texture = texture;
}

void DefaultTextures::Draw(GLuint VAO, GLenum primType, GLuint instances, GLsizei elements, bool drawElements) {
    glBindTexture(texEnum, texture);

    bitmap -> Draw(VAO, primType, instances, elements, drawElements);
}

//void DefaultTextures::Active(int index) {
//    glActiveTexture(GL_TEXTURE0 + index);
//}