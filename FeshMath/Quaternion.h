#pragma once

#ifndef QUATERNION_INCLUDED
#define QUATERNION_INCLUDED

#include "../Libraries/glmLibs.hpp"
#include "../Util/FeshAxis.hpp"

class Quaternion {
    public:
        Quaternion() = default;
        ~Quaternion() = default;

        static glm::quat setAngle(float angle, FeshAxis axis);
        static glm::quat eularAngle(const glm::vec3 rotation);
        static glm::quat normalize(glm::quat quat);

        static glm::vec3 getEulerAngles(glm::quat quat);
        
        static glm::quat useQuat(float x, float y, float z, float w);
};
#endif