#ifndef SPHERE_H_
#define SPHERE_H_

#include "vec3.h"
#include "ray.h"

typedef struct {
    Point3 center;
    double radius;
} Sphere;

double sphere_hit(Sphere *sphere, Ray *ray);

#endif // SPHERE_H_
