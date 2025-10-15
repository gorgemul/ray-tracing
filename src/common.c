#include "common.h"
#include <stdio.h>

#define UNIT_LENGTH 1

double rand_double(double min, double max)
{
    double range = rand() / (RAND_MAX + 1.0); // [0, 1)
    return min + (max - min) * range;
}

Vec3 rand_vec3(double min, double max)
{
    return (Vec3){ rand_double(min, max), rand_double(min, max), rand_double(min, max) };
}

Vec3 rand_unit_vec3(void)
{
    while (1) {
        Vec3 vec = rand_vec3(-UNIT_LENGTH, UNIT_LENGTH);
        double squared_len = vec3_squared_len(&vec);
        if (squared_len >= 1e-120 && squared_len <= UNIT_LENGTH)
            return vec3_div_scalar(&vec, 1, sqrt(squared_len));
    }
}
