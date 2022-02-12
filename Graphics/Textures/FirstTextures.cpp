#include "FirstTextures.h"

FirstTextures::FirstTextures(const std::string &file) {
    fromFile(file);
}

FirstTextures::~FirstTextures() {
    if(bitmap != nullptr) {
        delete bitmap;
    }

    glDeleteTextures(1, &texture);
}

void FirstTextures::fromFile(const std::string &file) {
    bitmap = new Bitmap();

    bitmap -> FlipImage(true);

    //Check for proper file.
    if(FileAssets::exist(file)) {
        results = bitmap -> getFromFile(file.c_str());

        if(results == -1) {
            throw "Texture doesn't exist!";

            delete bitmap;
            bitmap = nullptr;
        }
    }else {
        std::cout << "Image file can't be found" << std::endl;
    }

    glGenTextures(1, &texture);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, bitmap -> getWidth(), bitmap -> getHeight(), 0, GL_RGBA, GL_UNSIGNED_BYTE, bitmap -> getBytes());

    //Make it smooth
    glGenerateMipmap(GL_TEXTURE_2D);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    //How texture should be stamped
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAX_LEVEL, 1);
    glBindTexture(GL_TEXTURE_2D, 0);
}

void FirstTextures::Draw(GLuint VAO, GLenum primType, GLuint instances, GLsizei elements, bool drawElements) {
    bitmap -> Draw(VAO, primType, instances, elements, drawElements);
}

void FirstTextures::bind() {
    glBindTexture(GL_TEXTURE_2D, texture);
}