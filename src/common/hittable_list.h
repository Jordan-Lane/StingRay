#ifndef STINGRAY_HITTABLE_LIST_H
#define STINGRAY_HITTABLE_LIST_H

#include "hittable.h"

#include <memory>
#include <vector>

using std::shared_ptr;
using std::make_shared;

class hittable_list : public hittable {
    public:
        hittable_list() {}
        hittable_list(shared_ptr<hittable> object) { add(object); }

        void add( shared_ptr<hittable> object ) { objects.push_back(object); }
        void clear() { objects.clear(); }

        virtual bool hit( const ray& ray, double t_min, double t_max, hit_record& record) const override;

    public:
        std::vector<shared_ptr<hittable>> objects;
};

bool hittable_list::hit( const ray& ray, double t_min, double t_max, hit_record& record) const {
    hit_record temp_record;

    bool any_hits = false;
    double current_t = t_max;

    for(const auto& object : objects){
        if(object->hit(ray, t_min, current_t, temp_record)){
            any_hits = true;
            current_t = temp_record.t;
            record = temp_record;
        }
    }

    return any_hits;
}

#endif //STINGRAY_HITTABLE_LIST_H
