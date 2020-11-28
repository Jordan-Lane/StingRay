#ifndef STINGRAY_HITTABLE_H
#define STINGRAY_HITTABLE_H

#include "ray.h"

class material;

struct hit_record {
    point3 p;
    vec3 normal;
    shared_ptr<material> mat_ptr;
    double t;
    bool is_front_facing;

    inline void set_face_normal(const ray& r, const vec3& outward_normal){
        is_front_facing = dot(r.direction(), outward_normal) < 0;
        normal = is_front_facing ? outward_normal : -outward_normal;
    }
};

class hittable {
    public:
        virtual bool hit(const ray& r, double t_min, double t_max, hit_record& record) const = 0;
};

#endif //STINGRAY_HITTABLE_H
