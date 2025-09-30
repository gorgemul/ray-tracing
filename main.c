#include "vec3.h"
#include "color.h"
#include <stdio.h>

#define WIDTH  400
#define HEIGHT 300

int main(void)
{
    printf("P3\n%d %d\n255\n", WIDTH, HEIGHT);
    for (size_t h = 0; h < HEIGHT; ++h) {
        for (size_t w = 0; w < WIDTH; ++w) {
            Color color = color_init((double) w / 255, (double) h / 255, 0.0);
            color_write(&color, stdout);
        }
    }
}
