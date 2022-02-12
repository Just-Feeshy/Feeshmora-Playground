#pragma once

#include "Matrix.h"

glm::mat4 Matrix::perspective(float FOV, float aspect, float near, float far) {
    return glm::perspective(glm::radians(FOV / 2), aspect, near, far);
}

glm::mat4 Matrix::perspectiveLH(float FOV, float aspect, float near, float far) {
    return glm::perspectiveLH(glm::radians(FOV / 2), aspect, near, far);
}

glm::mat4 Matrix::transform(const glm::vec3 &translation, const glm::quat &rotation, const glm::vec3 &scale) {
    glm::mat4 t = glm::translate(translation);
    glm::mat4 r = QuatRotation(rotation);
    glm::mat4 s = glm::scale(scale);

    return t * r * s;
}

glm::mat4 Matrix::lookAt(const glm::vec3 &pos, const glm::vec3 &p, const glm::vec3 &y) {
    return glm::lookAt(pos, p, y);
}

glm::mat4 Matrix::lookAtLH(const glm::vec3 &pos, const glm::vec3 &p, const glm::vec3 &y) {
    return glm::lookAt(pos, p, y);
}

glm::mat4 Matrix::scale(const glm::vec3 &atm) {
    return glm::scale(atm);
}

glm::mat4 Matrix::transpose(glm::mat4 &m) {
    return glm::transpose(m);
}

glm::mat4 Matrix::inverse(glm::mat4 &m) {
    return glm::inverse(m);
}

glm::mat4 Matrix::QuatRotation(const glm::quat &quat) {
    float yy2 = 2.0f * quat.y * quat.y;
    float xy2 = 2.0f * quat.x * quat.y;
    float xz2 = 2.0f * quat.x * quat.z;
    float yz2 = 2.0f * quat.y * quat.z;
    float zz2 = 2.0f * quat.z * quat.z;
    float wz2 = 2.0f * quat.w * quat.z;
    float wy2 = 2.0f * quat.w * quat.y;
    float wx2 = 2.0f * quat.w * quat.x;
    float xx2 = 2.0f * quat.x * quat.x;

    glm::vec4 a = glm::vec4(-yy2 - zz2 + 1.0f, xy2 + wz2, xz2 - wy2, 0.0f);
    glm::vec4 b = glm::vec4(xy2 - wz2, -xx2 - zz2 + 1.0f, yz2 + wx2, 0.0f);
    glm::vec4 c = glm::vec4(xz2 + wy2, yz2 - wx2, -xx2 - yy2 + 1.0f, 0.0f);
    glm::vec4 d = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);

    return glm::mat4(a, b, c, d);
}

glm::vec3 Matrix::useVec3(float x, float y, float z) {
    return glm::vec3(x, y, z);
}

glm::vec4 Matrix::useVec4(float x, float y, float z, float w) {
    return glm::vec4(x, y, z, w);
}

glm::mat4 Matrix::useMat4(glm::vec4 &a, glm::vec4 &b, glm::vec4 &c, glm::vec4 &d) {
    return glm::mat4(a, b, c, d);
}

glm::mat4 Matrix::useMat4(float m) {
    return glm::mat4(m);
}

float Matrix::determinant4x4(glm::mat4 &m) {
    return glm::determinant(m);
}