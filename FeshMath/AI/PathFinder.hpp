#ifndef PATH_FINDER__INCLUDED
#define PATH_FINDER__INCLUDED

#include "../Matrix.cpp"

#include <cmath>

namespace PathFinder {
    static glm::vec3 getPathLocation(const glm::vec3 &v1, const glm::vec3 &v2) {
        return glm::vec3(0, 0, 0);
    }

    static glm::vec3 getAngleThroughPath(const glm::vec3 &v1, const glm::vec3 &v2) {
        const float y1 = atan2(v2.z - v1.z, v2.x - v1.x);

        return glm::vec3(0, -glm::degrees(y1), 0);
    }
}
#endif