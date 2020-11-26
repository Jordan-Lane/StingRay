#ifndef STINGRAY_STINGRAY_UTIL_H
#define STINGRAY_STINGRAY_UTIL_H

#include <cmath>
#include <cstdlib>
#include <limits>
#include <memory>

// Common Headers
#include "ray.h"
#include "vec3.h"

// Usings
using std::shared_ptr;
using std::make_shared;
using std::sqrt;

// Constants
const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;
color gradient_color1 = color(1.0, 1.0, 1.0);
color gradient_color2 = color(0.5, 0.7, 1.0);

// Utility Functions
inline double degrees_to_radians(double degrees){
    return degrees * pi / 180.0;
}

inline color linear_gradient(double t, color& color1, color& color2){
    return (1.0 - t) * color1 + t*color2;
}

inline double random_double(){
    return rand() / (RAND_MAX + 1.0);
}

inline double random_double(double min, double max){
    return min + (max-min)*random_double();
}

inline double clamp(double x, double min, double max){
    if(x < min) return min;
    if(x > max) return max;
    return x;
}

#endif //STINGRAY_STINGRAY_UTIL_H
