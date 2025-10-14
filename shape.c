#include "shape.h"
#include <assert.h>

bool hit(Shape *shape, Ray *ray, Interval *interval, struct HitRecord *record)
{
    (void)shape;
    (void)ray;
    (void)interval;
    (void)record;
    assert(false && "ERROR: virtual function hit can't be called directly, must register first");
    return false;
}

Shape shape_init(struct ShapeVTable *init_vtbl)
{
    static struct ShapeVTable default_vtbl = { .hit = &hit };
    struct ShapeVTable *vtbl = init_vtbl ? init_vtbl : &default_vtbl;
    return (Shape){ vtbl };
}

bool shape_hit(void *p, Ray *ray, Interval *interval, struct HitRecord *record)
{
    Shape *shape = (Shape*)p;
    return (*shape->vtbl->hit)(shape, ray, interval, record);
}
