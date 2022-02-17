#ifndef LIGHT_INCLUDED
#define LIGHT_INCLUDED

#include "Model.cpp"

enum LightType {
    POINT = 0,
    DIRECTION = 1
};

class Light: public Model {
    public:
        Light();
        Light(const LightType type);
        ~Light();

        void setLightToBe(const LightType type);

        //void update();
        void render();
        void draw(Shaders* shader) override;

        glm::mat3 getLightMatrix();
        //glm::mat4 getMatrix() override;

        void setColor(glm::vec3 color);
        glm::vec3 getColor() const;
        void setBrightness(const float value);
        float getBrightness() const;
        void setLinear(const float value);
        float getLinear() const;
        void setConstant(const float value);
        float getConstant() const;

        LightType getType() const;
    private:
        glm::vec3 color;

        float brightness = 1.0f;

        float linear = 3.0f;
        float constant = 0.7f;

        LightType type;
};
#endif