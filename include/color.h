#ifndef COLOR_H_
#define COLOR_H_

#include "vec3.h"
#include <stdio.h>

typedef Vec3 Color;

Color color_init(double r, double g, double b);
void color_write(Color *color, FILE *stream);

#endif // COLOR_H_
