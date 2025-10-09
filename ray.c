#include "ray.h"
#include "vec3.h"

Point3 ray_at(Ray *ray, double t)
{
    Vec3 distance = vec3_mul_scalar(&ray->direction, 1, t);
    return vec3_add(&ray->origin, 1, &distance);
}
