#pragma once

#ifndef MESH_INCLUDED
#define MESH_INCLUDED

#include "../FeshStates/BasicStates.h"
#include "../Graphics/Material.h"

#include "../Renderer/Render.hpp"
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

        virtual void update() = 0;
        virtual void updatePlayerPos(const glm::vec3 &pos) = 0;

        virtual glm::mat4 getMatrix() = 0;
    protected:
        std::vector<Shaders> shaderGroup;
        std::vector<GLuint> buffers;

        Material material;
        GLuint indicesCount = 0;

        GLuint VAO = 0;

        friend class BasicStates;

        virtual void draw(Shaders* shader) = 0;
        virtual void render() = 0;

        MeshInWorld movement;
};
#endif