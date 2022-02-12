#ifndef MATERIAL_INCLUDED
#define MATERIAL_INCLUDED

#include "../Libraries/Libs.hpp"

class Material {
    public:
        Material():
            diffuse(glm::vec3(0.0f)),
            specular(glm::vec3(0.0f)),
            ambient(glm::vec3(0.0f)),
            shininess(1.0f),
            alpha(1.0f) {};

        glm::vec3 getAmbient() const {
            return ambient;
        }

        glm::vec3 getDiffuse() const {
            return diffuse;
        }

        glm::vec3 getSpecular() const {
            return specular;
        }

        float getShininess() const {
            return shininess;
        }

        float getAlpha() const {
            return alpha;
        }
    private:
        glm::vec3 diffuse;
        glm::vec3 specular;
        glm::vec3 ambient;

        float shininess;
        float alpha;
};
#endif