#include "metal.h"
#include "shape.h"
#include "ray.h"
#include "vec3.h"
#include <stdbool.h>

static bool metal_scatter(Material *material, Ray *ray_in, struct HitRecord *record, Color *attenuation, Ray *ray_out)
{
    Metal *metal = (Metal*)material;
    Vec3 scaled_normal = vec3_mul_scalar(&record->normal, 2, -vec3_dot(&ray_in->direction, &record->normal), 2.0);
    Vec3 reflection_direction = vec3_add(&ray_in->direction, 1, &scaled_normal);
    *ray_out = (Ray){ .origin = record->hit_point, .direction = reflection_direction };
    *attenuation = material_atternuation(metal);
    return true;
}

Metal metal_init(Color albedo)
{
    static struct MaterialVTable vtbl = { .scatter = &metal_scatter, .attenuation = NULL };
    return (Metal){ .material = material_init(&vtbl, albedo) };
}
