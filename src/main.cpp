#include <iostream>

#include "stingray_util.h"

#include "camera.h"
#include "color.h"
#include "hittable_list.h"
#include "material.h"
#include "sphere.h"


// previously known as ray_color
color cast_ray(const ray &r, const hittable& world, int depth) {
    hit_record record;

    // Ray bounce limit - no more light is gathered
    if (depth <= 0){
        return color(0,0,0);
    }

    if(world.hit(r, 0.001, infinity, record)){

        //point3 target = record.p + record.normal + random_unit_vector();   // Lambertian reflection
        //point3 target = record.p + random_in_hemisphere(record.normal);      // Hemispherical reflection
        ray scattered;
        color attenuation;
        if (record.mat_ptr->scatter(r, record, attenuation, scattered))
            return attenuation * cast_ray(scattered, world, depth-1);
        return color(0,0,0);
    }

    vec3 unit_direction = unit_vector(r.direction());
    auto t = 0.5*(unit_direction.y() + 1.0);
    return (1.0 - t) * color(1.0, 1.0, 1.0) + t*color(0.5, 0.7, 1.0);
}


int main() {
    // To output picture, pipe the output of this program to a ppm image
    // Eg: './StingRay >> test.ppm'

    // Image
    const auto aspect_ratio = 16.0 / 9.0;
    const int image_width = 400;
    const int image_height = static_cast<int>( image_width / aspect_ratio );
    const int samples_per_pixel = 500;
    const int max_depth = 50;

    // World
    hittable_list world = hittable_list();
    auto material_ground = make_shared<lambertian>(color(0.8, 0.8, 0.0));
    auto material_center = make_shared<lambertian>(color(0.1, 0.2, 0.5));
    auto material_left   = make_shared<dielectric>(1.5);
    auto material_right  = make_shared<metal>(color(0.8, 0.6, 0.2), 0.0);

    world.add(make_shared<sphere>(point3( 0.0, -100.5, -1.0), 100.0, material_ground));
    world.add(make_shared<sphere>(point3( 0.0,    0.0, -1.0),   0.5, material_center));
    world.add(make_shared<sphere>(point3(-1.0,    0.0, -1.0),   0.5, material_left));
    world.add(make_shared<sphere>(point3(-1.0,    0.0, -1.0), -0.45, material_left));
    world.add(make_shared<sphere>(point3( 1.0,    0.0, -1.0),   0.5, material_right));

    camera cam(point3(-2,2,1), point3(0,0,-1), vec3(0,1,0), 20, aspect_ratio);

    // Render
    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = image_height-1; j >= 0; --j) {
        std::cerr << "\rScan-lines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < image_width; ++i){
            color pixel_color(0,0,0);

            for(int s = 0; s < samples_per_pixel; ++s) {
                auto u = (i + random_double()) / (image_width - 1);
                auto v = (j + random_double()) / (image_height - 1);

                ray r = cam.get_ray(u, v);
                pixel_color += cast_ray(r, world, max_depth);
            }
            write_color(std::cout, pixel_color, samples_per_pixel);
        }
    }

    std::cerr << "\nDone.\n";
}