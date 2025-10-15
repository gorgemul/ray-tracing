#ifndef SPHERE_H_
#define SPHERE_H_

#include "vec3.h"
#include "ray.h"
#include "shape.h"
#include "material.h"

typedef struct {
    Shape  shape;
    Material *material;
    Point3 center;
    double radius;
} Sphere;

Sphere sphere_init(void *material, Point3 center, double radius);

#endif // SPHERE_H_
