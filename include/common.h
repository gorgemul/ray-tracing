#ifndef COMMON_H_
#define COMMON_H_

#include "vec3.h"
#include <math.h> // for INFINITY
#include <stdlib.h>

#define PI  3.14159265358979323846

double rand_double(double min, double max);
Vec3 rand_unit_vec3(void);

#endif // COMMON_H_
