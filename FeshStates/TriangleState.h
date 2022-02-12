#ifndef TRIANGLE_INCLUDED
#define TRIANGLE_INCLUDED

#include "BasicStates.h"

class TriangleState: public BasicStates {
    public:
        TriangleState() = default;
        ~TriangleState();

        void onCreate() override;

        void update(float elapsed) override;
    private:
        std::unique_ptr<Shaders> triangleShaders = 0;
        
        std::unique_ptr<FirstTextures> triangleTextures = 0;

        GLuint shaderProgram = 0;
        GLuint VAO, VBO, EBO = 0;
};
#endif