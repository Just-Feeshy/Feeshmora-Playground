#pragma once

#ifndef RENDER_INCLUDED
#define RENDER_INCLUDED

#include "../UniqueBuffers/StencilBuffers.cpp"
#include "../Libraries/glmLibs.hpp"

#include <vector>
#include <string>
#include <map>
#include <iostream>

namespace Vertices {
    GLfloat triangleVertices[] = {
        -0.3f, -0.3f, 0.0f,    0.2f, 0.8f, 0.8f,    0.0f, 0.0f,
        0.0f,  0.3f, 0.0f,   0.8f, 0.2f, 0.8f,  2.5f, 5.0f,
        0.3f, -0.3f, 0.0f,     0.8f, 0.8f, 0.2f,    5.0f, 0.0f
    };
};

/**
* Yes. I'm keeping it like this.
* Cry about it.
*/
class Render {
    public:
        Render() {
            uniformValues = new std::map<std::string, GLfloat*>;
        };

        ~Render() {
            if(uniformValues -> size() > 0) {
                uniformValues -> clear();
            }

            if(uniformValues != nullptr) {
                delete uniformValues;
            }
            
            glDeleteProgram(shaderProgram);
        };

        void useShaderProgram() {
            glUseProgram(shaderProgram);
        }

        void update() {
            useShaderProgram();
        }

        //Uniform for GLSL
        void uniformFloat(const char* name, float value) const {
            uniformValues -> insert(std::pair<std::string, GLfloat*>(std::string(name), &value));
            glUniform1f(glGetUniformLocation(shaderProgram, name), value);
        }

        void uniformInt(const char* name, int value) const {
            float fvalue = (float)value;
            
            uniformValues -> insert(std::pair<std::string, GLfloat*>(std::string(name), &fvalue));
            glUniform1i(glGetUniformLocation(shaderProgram, name), value);
        }

        void uniformVec3(const char* name, const glm::vec3 &v) const {
            GLfloat* value = const_cast<GLfloat*>(glm::value_ptr(v));
            
            uniformValues -> insert(std::pair<std::string, GLfloat*>(std::string(name), value));
            glUniform3f(glGetUniformLocation(shaderProgram, name), v.x, v.y, v.z);
        }

        void uniformVec4(const char* name, const glm::vec4 &v) const {
            GLfloat* value = const_cast<GLfloat*>(glm::value_ptr(v));
            
            uniformValues -> insert(std::pair<std::string, GLfloat*>(std::string(name), value));
            glUniform4f(glGetUniformLocation(shaderProgram, name), v.x, v.y, v.z, v.w);
        }

        void uniformMat3(const char* name, const glm::mat3 &m) const {
            GLfloat* value = const_cast<GLfloat*>(glm::value_ptr(m));
            
            uniformValues -> insert(std::pair<std::string, GLfloat*>(std::string(name), value));
            glUniformMatrix3fv(glGetUniformLocation(shaderProgram, name), 1, GL_FALSE, glm::value_ptr(m));
        }

        void uniformMat4(const char* name, const glm::mat4 &m) const {
            GLfloat* value = const_cast<GLfloat*>(glm::value_ptr(m));

            //std::cout << value[0] << std::endl;
            
            uniformValues -> insert(std::pair<std::string, GLfloat*>(std::string(name), value));

            
            glUniformMatrix4fv(glGetUniformLocation(shaderProgram, name), 1, GL_FALSE, glm::value_ptr(m));
        }

        //uniform for GLSL but with string
        void uniformFloat(const std::string &name, float value) const {
            uniformValues -> insert(std::pair<std::string, GLfloat*>(std::string(name), &value));
            glUniform1f(glGetUniformLocation(shaderProgram, name.c_str()), value);
        }

        void uniformInt(const std::string &name, int value) const {
            float fvalue = (float)value;
            
            uniformValues -> insert(std::pair<std::string, GLfloat*>(std::string(name), &fvalue));
            glUniform1i(glGetUniformLocation(shaderProgram, name.c_str()), value);
        }

        void uniformVec3(const std::string &name, const glm::vec3 &v) const {
            GLfloat* value = const_cast<GLfloat*>(glm::value_ptr(v));

            uniformValues -> insert(std::pair<std::string, GLfloat*>(std::string(name), value));
            glUniform3f(glGetUniformLocation(shaderProgram, name.c_str()), v.x, v.y, v.z);
        }

        void uniformVec4(const std::string &name, const glm::vec4 &v) const {
            GLfloat* value = const_cast<GLfloat*>(glm::value_ptr(v));
            
            uniformValues -> insert(std::pair<std::string, GLfloat*>(std::string(name), value));
            glUniform4f(glGetUniformLocation(shaderProgram, name.c_str()), v.x, v.y, v.z, v.w);
        }

        void uniformMat3(const std::string &name, const glm::mat3 &m) const {
            GLfloat* value = const_cast<GLfloat*>(glm::value_ptr(m));
            
            uniformValues -> insert(std::pair<std::string, GLfloat*>(std::string(name), value));
            glUniformMatrix3fv(glGetUniformLocation(shaderProgram, name.c_str()), 1, GL_FALSE, glm::value_ptr(m));
        }

        void uniformMat4(const std::string &name, const glm::mat4 &m) const {
            GLfloat* value = const_cast<GLfloat*>(glm::value_ptr(m));
            
            uniformValues -> insert(std::pair<std::string, GLfloat*>(std::string(name), value));
            
            glUniformMatrix4fv(glGetUniformLocation(shaderProgram, name.c_str()), 1, GL_FALSE, glm::value_ptr(m));
        }

        std::map<std::string, GLfloat*>* getUniformValues() const {
            return uniformValues;
        }

        //use value_ptr
        void uniformMat3(const std::string &name, const GLfloat* m) const {
            //glUniformMatrix3fv(glGetUniformLocation(shaderProgram, name.c_str()), 1, GL_FALSE, m);
        }

        void uniformMat4(const std::string &name, GLfloat* m) const {
            //glUniformMatrix4fv(glGetUniformLocation(shaderProgram, name.c_str()), 1, GL_FALSE, m);
        }
    protected:

        /**
        * GLfloat is needed to store every 
        * numerical value.
        */
        std::map<std::string, GLfloat*>* uniformValues;

        GLuint shaderProgram = 0;
};
#endif