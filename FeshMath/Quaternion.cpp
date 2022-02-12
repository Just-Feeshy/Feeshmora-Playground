#pragma once

#include "Quaternion.h"

glm::quat Quaternion::setAngle(float angle, FeshAxis axis) {
    if(axis == X) {
        return glm::angleAxis(glm::radians(angle), glm::vec3(1, 0, 0));
    }else if(axis == Y) {
        return glm::angleAxis(glm::radians(angle), glm::vec3(0, 1, 0));
    }

    return glm::angleAxis(glm::radians(angle), glm::vec3(0, 0, 1));
}

glm::quat Quaternion::eularAngle(const glm::vec3 rotation) {
    glm::vec3 vec;
    
    vec.x = glm::radians(rotation.x);
    vec.y = glm::radians(rotation.y);
    vec.z = glm::radians(rotation.z);

    return glm::quat(vec);
}

glm::quat normalize(glm::quat quat) {
    return glm::normalize(quat);
}

glm::vec3 Quaternion::getEulerAngles(glm::quat quat) {
    glm::vec3 angle = glm::eulerAngles(quat);
    angle = glm::vec3(glm::degrees(angle.x), glm::degrees(angle.y), glm::degrees(angle.z));

    return angle;
}

glm::quat Quaternion::useQuat(float x, float y, float z, float w) {
    return glm::quat(x, y, z, w);
}