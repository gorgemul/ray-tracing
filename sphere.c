#include "sphere.h"
#include "interval.h"
#include <math.h>
#include <assert.h>

static bool sphere_hit(Shape *shape, Ray *ray, Interval *interval, struct HitRecord *record)
{
    Sphere *sphere = (Sphere*)shape;
    Vec3 OC = vec3_sub(&sphere->center, 1, &ray->origin);
    double a = vec3_dot(&ray->direction, &ray->direction);
    double b = -2 * vec3_dot(&ray->direction, &OC);
    double c = vec3_dot(&OC, &OC) - sphere->radius * sphere->radius;
    double discriminant = b * b - 4 * a * c;
    if (discriminant < 0) return false;
    double t = (-b - sqrt(discriminant)) / (2 * a);
    if (!interval_surrounds(interval, t)) {
        t = (-b + sqrt(discriminant)) / (2 * a);
        if (!interval_surrounds(interval, t)) return false;
    }
    Point3 hit_point = ray_at(ray, t);
    Vec3 outward = vec3_sub(&hit_point, 1, &sphere->center);
    Vec3 normal_outward = vec3_div_scalar(&outward, 1, sphere->radius);
    record->ray_t = t;
    record->hit_point = hit_point;
    record->material = sphere->material;
    if (vec3_dot(&ray->direction, &normal_outward) > 0.0) {
        record->normal = vec3_neg(&normal_outward);
        record->is_ray_outside_shape = false;
    } else {
        record->normal = normal_outward;
        record->is_ray_outside_shape = true;
    }
    return true;
}

Sphere sphere_init(void *material, Point3 center, double radius)
{
    assert(radius > 0.0 && "sphere_init radius is less than 0");
    static struct ShapeVTable vtbl = { .hit = &sphere_hit };
    Shape shape = shape_init(&vtbl);
    return (Sphere){ .shape = shape, .material = (Material*)material, .center = center, .radius = radius };
}
