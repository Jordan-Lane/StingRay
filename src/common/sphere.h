#ifndef STINGRAY_SPHERE_H
#define STINGRAY_SPHERE_H

#include "hittable.h"
#include "vec3.h"

class sphere : public hittable {
    public:
        sphere() {}
        sphere(point3 center_point, double r, shared_ptr<material> mat)
            : center(center_point), radius(r), mat_ptr(mat) {};

        virtual bool hit(const ray &r, double t_min, double t_max, hit_record &record) const override;

    public:
        point3 center;
        double radius;
        shared_ptr<material> mat_ptr;
};

// TODO: REVIEW THE VECTOR MATH BEHIND THIS INTERSECTION
bool sphere::hit(const ray &ray, double t_min, double t_max, hit_record &record) const {
    vec3 oc = ray.origin() - center;

    // Sphere-ray intersection is a quadratic equation
    auto a = dot(ray.direction(), ray.direction());
    auto b = 2.0 * dot(oc, ray.direction());
    auto c = dot(oc, oc) - (radius * radius);

    auto discriminant = b*b - 4*a*c;
    if ( discriminant < 0 ){
        return false;
    }

    auto sqrt_discriminant = sqrt(discriminant);
    auto root = (-b - sqrt_discriminant) / (2 * a);
    if ( root < t_min || t_max < root ){
        root = (-b + sqrt_discriminant) / (2 * a);
        if( root < t_min || t_max < root )
            return false;
    }

    record.t = root;
    record.p = ray.at(root);
    record.mat_ptr = mat_ptr;

    vec3 outward_normal = (record.p - center) / radius;
    record.set_face_normal(ray, outward_normal);

    return true;
}

#endif //STINGRAY_SPHERE_H
