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
            glEnable(GL_STENCIL_TEST);

            glDepthFunc(GL_LESS);

            //glStencilFunc(GL_NOTEQUAL, 1, 0xFF);
            //glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
        }

        void useShaderProgram() {
            glUseProgram(shaderProgram);
        }

        void setDepthTestEnable(const bool enable) {
            if(isUsingDepthTest != enable) {
                if(enable) {
                    glEnable(GL_DEPTH_TEST);
                }else {
                    glDisable(GL_DEPTH_TEST);
                }

                isUsingDepthTest = enable;
            }
        }

        void setStencilMask(const GLuint mask) {
            if(w_daStencilMask != mask) {
                glStencilMask(mask);
                
                w_daStencilMask = mask;
            }
        }

        void update() {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
            
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

        //uniform for GLSL but with string
        void uniformFloat(const std::string &name, float value) const {
            glUniform1f(glGetUniformLocation(shaderProgram, name.c_str()), value);
        }

        void uniformInt(const std::string &name, int value) const {
            glUniform1i(glGetUniformLocation(shaderProgram, name.c_str()), value);
        }

        void uniformVec3(const std::string &name, const glm::vec3 &v) const {
            glUniform3f(glGetUniformLocation(shaderProgram, name.c_str()), v.x, v.y, v.z);
        }

        void uniformVec4(const std::string &name, const glm::vec4 &v) const {
            glUniform4f(glGetUniformLocation(shaderProgram, name.c_str()), v.x, v.y, v.z, v.w);
        }

        void uniformMat3(const std::string &name, const glm::mat3 &m) const {
            glUniformMatrix3fv(glGetUniformLocation(shaderProgram, name.c_str()), 1, GL_FALSE, glm::value_ptr(m));
        }

        void uniformMat4(const std::string &name, const glm::mat4 &m) const {
            glUniformMatrix4fv(glGetUniformLocation(shaderProgram, name.c_str()), 1, GL_FALSE, glm::value_ptr(m));
        }
    protected:
        GLuint shaderProgram = 0;
    private:
        bool isUsingDepthTest = true;

        //OpenGL Stuff
        GLuint w_daStencilMask = 0;
        GLuint t_daStencilMask = 0;
        GLint daStencilComparison = 0;

        GLenum daStencilFunc;
};
#endif