#include "lambertian.h"
#include "shape.h"
#include "ray.h"
#include "vec3.h"
#include "common.h"
#include <stdbool.h>

static bool lambertian_scatter(Material *material, Ray *ray_in, struct HitRecord *record, Color *attenuation, Ray *ray_out)
{
    (void)ray_in;
    Lambertian *lambertian = (Lambertian*)material;
    Vec3 rand_unit_vec = rand_unit_vec3();
    Vec3 scattered_direction = vec3_add(&record->normal, 1, &rand_unit_vec);
    if (vec3_is_zero_vector(&scattered_direction))
        scattered_direction = record->normal;
    *ray_out = (Ray){ .origin = record->hit_point, .direction = scattered_direction };
    *attenuation = material_atternuation(lambertian);
    return true;
}

Lambertian lambertian_init(Color albedo)
{
    static struct MaterialVTable vtbl = { .scatter = &lambertian_scatter, .attenuation = NULL };
    return (Lambertian){ .material = material_init(&vtbl, albedo) };
}
