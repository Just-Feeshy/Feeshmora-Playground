#ifndef RENDER_INCLUDED
#define RENDER_INCLUDED

#include "../Libraries/Libs.hpp"
#include "../Libraries/glmLibs.hpp"

#include <vector>
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
        Render() = default;

        ~Render() {
            glDeleteProgram(shaderProgram);
        };

        void Init() {
            glEnable(GL_DEPTH_TEST);
            glMatrixMode(GL_MODELVIEW);

            //glEnable(GL_STENCIL_TEST);
            //glEnable(GL_BLEND);
            //glEnable(GL_LINE_SMOOTH);
            //glEnable(GL_MULTISAMPLE);
            //glEnable();

            //glDepthFunc(GL_LESS);
            //glFrontFace(GL_CW);
        }

        void useShaderProgram() {
            glUseProgram(shaderProgram);
        }

        void update() {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            useShaderProgram();
        }

        //Uniform for GLSL
        void uniformFloat(const char* name, float value) const {
            glUniform1f(glGetUniformLocation(shaderProgram, name), value);
        }

        void uniformInt(const char* name, int value) const {
            glUniform1i(glGetUniformLocation(shaderProgram, name), value);
        }

        void uniformVec3(const char* name, const glm::vec3 &v) const {
            glUniform3f(glGetUniformLocation(shaderProgram, name), v.x, v.y, v.z);
        }

        void uniformVec4(const char* name, const glm::vec4 &v) const {
            glUniform4f(glGetUniformLocation(shaderProgram, name), v.x, v.y, v.z, v.w);
        }

        void uniformMat3(const char* name, const glm::mat3 &m) const {
            glUniformMatrix3fv(glGetUniformLocation(shaderProgram, name), 1, GL_FALSE, glm::value_ptr(m));
        }

        void uniformMat4(const char* name, const glm::mat4 &m) const {
            glUniformMatrix4fv(glGetUniformLocation(shaderProgram, name), 1, GL_FALSE, glm::value_ptr(m));
        }
    protected:
        GLuint shaderProgram = 0;
};
#endif