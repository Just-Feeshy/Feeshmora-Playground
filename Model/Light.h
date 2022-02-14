#ifndef LIGHT_INCLUDED
#define LIGHT_INCLUDED

#include "Model.cpp"

class Light: public Model {
    public:
        Light();
        ~Light();

        //void update();
        void render();
        void draw(Shaders* shader) override;

        glm::mat3 getLightMatrix();
        //glm::mat4 getMatrix() override;

        void setColor(glm::vec3 color);

        glm::vec3 getColor() const;
    private:
        glm::vec3 color;
};
#endif