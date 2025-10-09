#include "sphere.h"
#include <math.h>

double sphere_hit(Sphere *sphere, Ray *ray)
{
    Vec3 OC = vec3_sub(&sphere->center, 1, &ray->origin);
    double a = vec3_dot(&ray->direction, &ray->direction);
    double b = -2 * vec3_dot(&ray->direction, &OC);
    double c = vec3_dot(&OC, &OC) - sphere->radius * sphere->radius;
    double discriminant = b * b - 4 * a * c;
    return discriminant < 0 ? -1.0 : (-b - sqrt(discriminant)) / (2 * a); // get the first hit point and ignore sphere behind the camera right now
}
