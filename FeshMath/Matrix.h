#pragma once

#ifndef MATRIX_INCLUDED
#define MATRIX_INCLUDED

#include "Quaternion.cpp"

class Matrix {
    public:
        Matrix() = default;

        static glm::mat4 perspective(float FOV, float aspect, float near, float far);
        static glm::mat4 perspectiveLH(float FOV, float aspect, float near, float far);
        static glm::mat4 transform(const glm::vec3 &translation, const glm::quat &rotation, const glm::vec3 &scale);
        static glm::mat4 lookAt(const glm::vec3 &pos, const glm::vec3 &p, const glm::vec3 &y);
        static glm::mat4 lookAtLH(const glm::vec3 &pos, const glm::vec3 &p, const glm::vec3 &y);
        static glm::mat4 scale(const glm::vec3 &atm);

        static glm::mat4 transpose(glm::mat4 &m);
        static glm::mat4 inverse(glm::mat4 &m);

        static glm::mat4 QuatRotation(const glm::quat &quat);

        static glm::vec3 useVec3(float x, float y, float z);
        static glm::vec4 useVec4(float x, float y, float z ,float w);
        static glm::mat4 useMat4(float m);
        static glm::mat4 useMat4(glm::vec4 &a, glm::vec4 &b, glm::vec4 &c, glm::vec4 &d);

        static float determinant4x4(glm::mat4 &m);
};
#endif