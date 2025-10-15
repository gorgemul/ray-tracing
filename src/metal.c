#include "metal.h"
#include "shape.h"
#include "ray.h"
#include "vec3.h"
#include "common.h"
#include <stdbool.h>

static bool metal_scatter(Material *material, Ray *ray_in, struct HitRecord *record, Color *attenuation, Ray *ray_out)
{
    Metal *metal = (Metal*)material;
    Vec3 scaled_normal = vec3_mul_scalar(&record->normal, 2, -vec3_dot(&ray_in->direction, &record->normal), 2.0);
    Vec3 reflection_direction = vec3_add(&ray_in->direction, 1, &scaled_normal);
    Vec3 unit_reflection_direction = vec3_unit_vector(&reflection_direction);
    Vec3 rand_unit_vec = rand_unit_vec3();
    Vec3 fuzzy_rand_unit_vec = vec3_mul_scalar(&rand_unit_vec, 1, metal->fuzzy_rate);
    Vec3 fuzzy_direction = vec3_add(&unit_reflection_direction, 1, &fuzzy_rand_unit_vec);
    *ray_out = (Ray){ .origin = record->hit_point, .direction = fuzzy_direction };
    *attenuation = material_atternuation(metal);
    return vec3_dot(&ray_out->direction, &record->normal) > 0;
}

Metal metal_init(Color albedo, double fuzzy_rate)
{
    static struct MaterialVTable vtbl = { .scatter = &metal_scatter, .attenuation = NULL };
    if (fuzzy_rate <= 0.0) fuzzy_rate = 0.0;
    if (fuzzy_rate >= 1)   fuzzy_rate = 1.0;
    return (Metal){ .material = material_init(&vtbl, albedo), .fuzzy_rate = fuzzy_rate };
}
