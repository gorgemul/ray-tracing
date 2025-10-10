#ifndef SPHERE_H_
#define SPHERE_H_

#include "vec3.h"
#include "ray.h"
#include "shape.h"

typedef struct {
    Shape  super;
    Point3 center;
    double radius;
} Sphere;

Sphere sphere_init(Point3 center, double radius);

#endif // SPHERE_H_
