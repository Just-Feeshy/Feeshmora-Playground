#pragma once

#ifndef MODEL_INCLUDED
#define MODEL_INCLUDED

#include "../Graphics/Textures/BackendTextures.cpp"
#include "../Renderer/Helpers/RenderManager.cpp"
#include "MeshVertices.cpp"

#include <cmath>

using namespace std;

class Model: public Mesh {
    public:
        Model() {
            movement.position = {0.0f, 0.0f, 0.0f};
            direction = {0.0f, 0.0f, 0.0f};
            upwards = {0.0f, 1.0f, 0.0f};

            elapsed = 0.0f;

            setRotation(0,0,0);
        };
        
        virtual ~Model() {};

        void render() override;
        virtual void update(const float& elapsed) override;
        virtual void draw(Shaders* shader) override;
        virtual void draw(Shaders* shader, const int index) override;
        virtual void implementWindow(WindowDisplay* window) override;

        Model* create(MeshVertices *meshConfig);

        void createVAO();
        void bindVAO();

        void compile();

        void createBuffer(GLenum type, MeshVertices &m, bool indices);
        void setTexture(const std::string file, const TexEnum type, int sides, const TexMap map);

        float getElapsed() const {
            return elapsed;
        }
    protected:
        float elapsed;

        BackendTextures texture;
        MeshVertices alignment;

        glm::vec3 direction;
        glm::vec3 angle;
        glm::vec3 upwards;

        int totalIndices;

        bool created;

        float alpha;
    public:
        virtual void setRotation(float yaw, float pitch, float roll);

        void setPosition(float x, float y, float z) {
            movement.position = {x, y, z};
        }

        void setPosition(const glm::vec3 pos) {
            movement.position = pos;
        }

        virtual void moveForward();
        virtual void moveBackwards();
        virtual void moveLeft();
        virtual void moveRight();

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

        glm::vec3 getDirection() const {
            return direction;
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