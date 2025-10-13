#include "color.h"
#include <stdio.h>
#include <math.h>

double to_gamma_space(double linear)
{
    return linear <= 0 ? 0 : sqrt(linear);
}

Color color_init(double r, double g, double b)
{
    if (r < 0.0 || r > 1.0) r = r < 0.0 ? 0.0 : 1.0;
    if (g < 0.0 || g > 1.0) g = g < 0.0 ? 0.0 : 1.0;
    if (b < 0.0 || b > 1.0) b = b < 0.0 ? 0.0 : 1.0;
    return (Color){ .x = r, .y = g, .z = b };
}

void color_write(Color *color, FILE *stream)
{
    int r = (int)(255.999 * to_gamma_space(color->x));
    int g = (int)(255.999 * to_gamma_space(color->y));
    int b = (int)(255.999 * to_gamma_space(color->z));
    fprintf(stream, "%d %d %d\n", r, g, b);
}
