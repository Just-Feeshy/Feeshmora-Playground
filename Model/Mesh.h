#pragma once

#ifndef MESH_INCLUDED
#define MESH_INCLUDED

#include "../FeshStates/BasicStates.h"

#include "../Renderer/Render.hpp"
#include "../Graphics/Material.cpp"
#include "../FeshMath/Matrix.cpp"

#include <vector>

/**
* Provides a base build for model rendering.
*/

struct MeshVertex {
    glm::vec3 vertices;
    glm::vec2 texCoords;
    glm::vec3 colorRBG;
    glm::vec3 normalCoords;
};

struct MeshInWorld {
    glm::vec3 position;
    glm::vec3 rotation;
    glm::vec3 velocity;
};

class Mesh {
    public:
        Mesh() = default;

        ~Mesh() {
            if(buffers.size() > 0) {
                glDeleteBuffers(static_cast<GLsizei>(buffers.size()), buffers.data());
            }
        
            if(VAO != 0 && VAO) {
                glDeleteVertexArrays(1, &VAO);
            }
        }

        virtual void update(const float& elapsed) = 0;

        GLuint getVAO() const {
            return VAO;
        }

        virtual void draw(Shaders* shader) = 0;

        virtual void implementWindow(WindowDisplay* window) = 0;

        /**
        For models that use a GLSL array.
        Example: Light
        */
        virtual void draw(Shaders* shader, const int index) = 0;
        virtual void render() = 0;
    protected:
        std::vector<Shaders> shaderGroup;
        std::vector<GLuint> buffers;

        Material material;
        GLuint indicesCount = 0;

        GLuint VAO = 0;

        friend class BasicStates;

        MeshInWorld movement;
};
#endif