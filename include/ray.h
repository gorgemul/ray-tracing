#ifndef RAY_H_
#define RAY_H_

#include "vec3.h"

typedef struct {
    Point3 origin;
    Vec3 direction;
} Ray;

Point3 ray_at(Ray *ray, double t);

#endif // RAY_H_
