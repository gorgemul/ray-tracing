#ifndef SHAPE_H_
#define SHAPE_H_

#include "vec3.h"
#include "ray.h"
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
    bool (*hit)(Shape *shape, Ray *ray, double t_min, double t_max, HitRecord *record);
};

Shape shape_init(bool (*hit_func)(Shape *shape, Ray *ray, double t_min, double t_max, HitRecord *record));
bool shape_hit(void *p, Ray *ray, double t_min, double t_max, HitRecord *record);

#endif // SHAPE_H_
