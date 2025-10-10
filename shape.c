#include "shape.h"
#include <assert.h>

static struct ShapeVTable vtbl;

bool hit(Shape *shape, Ray *ray, double t_min, double t_max, HitRecord *record)
{
    (void)shape;
    (void)ray;
    (void)t_min;
    (void)t_max;
    (void)record;
    assert(false && "ERROR: virtual function hit can't be called directly, must register first");
    return false;
}

Shape shape_init(bool (*hit_func)(Shape *shape, Ray *ray, double t_min, double t_max, HitRecord *record))
{
    vtbl.hit = hit_func ? hit_func : &hit;
    return (Shape){ &vtbl };
}

bool shape_hit(void *p, Ray *ray, double t_min, double t_max, HitRecord *record)
{
    Shape *shape = (Shape*)p;
    return (*shape->vtbl->hit)(shape, ray, t_min, t_max, record);
}
