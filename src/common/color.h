#ifndef STINGRAY_COLOR_H
#define STINGRAY_COLOR_H

#include "vec3.h"

void write_color(std::ostream &out_stream, color pixel_color){
    // Write the translated value [0, 255] value of each color component
    out_stream << static_cast<int>(255.99 * pixel_color.x()) << ' '
               << static_cast<int>(255.99 * pixel_color.y()) << ' '
               << static_cast<int>(255.99 * pixel_color.z()) << '\n';
}

#endif //STINGRAY_COLOR_H
