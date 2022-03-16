#pragma once

#ifndef MODEL_INCLUDED
#define MODEL_INCLUDED

#include "../Graphics/Textures/DefaultTextures.cpp"
#include "MeshVertices.cpp"

#include <cmath>

class Model: public Mesh {
    public:
        Model() {
            movement.position = {0.0f, 0.0f, 0.0f};
            direction = {0.0f, 0.0f, 0.0f};
            upwards = {0.0f, 1.0f, 0.0f};
        };
        
        ~Model();

        void update() override;
        void render() override;
        virtual void draw(Shaders* shader) override;
        virtual void draw(Shaders* shader, const int index) override;

        void create(MeshVertices &meshConfig);

        void createVAO();
        void bindVAO();

        void compile();

        void createBuffer(GLenum type, MeshVertices &m, bool indices);
        void setTexture(const std::string file, const TexEnum type, const TexParams params, const TexParams anti, int sides, const TexMap map);
    protected:
        DefaultTextures texture;
        MeshVertices alignment;

        glm::vec3 direction;
        glm::vec3 angle;
        glm::vec3 upwards;

        int totalIndices;

        bool created;
    public:
        virtual void setRotation(float yaw, float pitch, float roll);

        void setPosition(float x, float y, float z) {
            movement.position = {x, y, z};
        }

        void moveForward(float elapsed) {
            movement.position += direction * elapsed;
        }

        void moveBackwards(float elapsed) {
            movement.position -= direction * elapsed;
        }

        void moveLeft(float elapsed) {
            movement.position -= angle * elapsed;
        }

        void moveRight(float elapsed) {
            movement.position += angle * elapsed;
        }

        float getDirection(FeshAxis axis) const {
            if(axis == X) {
                return direction.x;
            }else if(axis == Y) {
                return direction.y;
            }else if(axis == Z) {
                return direction.z;
            }

            return direction.x;
        }

        float getRotation(FeshAxis axis) const {
            if(axis == X) {
                return movement.rotation.x;
            }else if(axis == Y) {
                return movement.rotation.y;
            }else if(axis == Z) {
                return movement.rotation.z;
            }

            return movement.rotation.x;
        }

        glm::vec3 getRotation() const {
            return movement.rotation;
        }

        float getPosition(FeshAxis axis) const {
            if(axis == X) {
                return movement.position.x;
            }else if(axis == Y) {
                return movement.position.y;
            }else if(axis == Z) {
                return movement.position.z;
            }

            return movement.position.x;
        }

        glm::vec3 getPosition() const {
            return movement.position;
        }

        virtual glm::mat4 getMatrix();
};
#endif