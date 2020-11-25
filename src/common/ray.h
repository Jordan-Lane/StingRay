#ifndef STINGRAY_RAY_H
#define STINGRAY_RAY_H

#include "vec3.h"

class ray {
    public:
        ray(){};
        ray(const point3& origin, const point3& direction)
            : orig(origin), dir(direction)
        {}

        point3 origin() const { return orig; }
        point3 direction() const { return dir; }

        point3 at(int t){
            return orig + (t * dir);
        }

    public:
        point3 orig;
        vec3 dir;
};

#endif //STINGRAY_RAY_H
