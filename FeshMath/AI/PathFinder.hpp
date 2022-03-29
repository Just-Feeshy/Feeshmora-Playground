#ifndef PATH_FINDER__INCLUDED
#define PATH_FINDER__INCLUDED

#include "../Matrix.cpp"

#include <cmath>

/**
* Basic math header.
*/
namespace PathFinder {
    static glm::vec3 getAngleThroughPath(const glm::vec3 &v1, const glm::vec3 &v2) {
        const float y1 = atan2(v2.z - v1.z, v2.x - v1.x);

        return glm::vec3(0, -glm::degrees(y1), 0);
    }

    /**
    * 3D Pythagorean Theorem leak lmao.
    */
    static float getDistance(const glm::vec3 &v1, const glm::vec3 &v2) {
        return sqrt(pow(v2.x - v1.x, 2) + pow(v2.y - v1.y, 2) + pow(v2.z - v1.z, 2));
    }
}
#endif