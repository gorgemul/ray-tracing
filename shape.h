#ifndef SHAPE_H_
#define SHAPE_H_

#include "vec3.h"
#include "ray.h"
#include "interval.h"
#include <stdbool.h>

typedef struct {
    Point3 hit_point;
    Vec3 normal;
    double ray_t;
    bool is_ray_outside_shape;
} HitRecord;

struct ShapeVTable;

typedef struct {
    struct ShapeVTable *vtbl;
} Shape;

struct ShapeVTable {
    bool (*hit)(Shape *shape, Ray *ray, Interval *interval, HitRecord *record);
};

Shape shape_init(struct ShapeVTable *init_vtbl);
bool shape_hit(void *p, Ray *ray, Interval *interval, HitRecord *record);

#endif // SHAPE_H_
