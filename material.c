#include "material.h"
#include <assert.h>

bool scatter(Material *material, Ray *ray_in, struct HitRecord *record, Color *attenuation, Ray *ray_out)
{
    (void)material;
    (void)ray_in;
    (void)record;
    (void)attenuation;
    (void)ray_out;
    assert(false && "ERROR: virtual function scatter can't be called directly, must register first");
    return false;
}

Color attenuation(Material *material)
{
    return material->albedo;
}

Material material_init(struct MaterialVTable *init_vtbl, Color albedo)
{
    static struct MaterialVTable default_vtbl = { .scatter = &scatter };
    struct MaterialVTable *vtbl = init_vtbl ? init_vtbl : &default_vtbl;
    vtbl->attenuation = &attenuation;
    return (Material){ vtbl, albedo };
}

bool material_scatter(void *p, Ray *ray_in, struct HitRecord *record, Color *attenuation, Ray *ray_out)
{
    Material *material = (Material*)p;
    return (*material->vtbl->scatter)(material, ray_in, record, attenuation, ray_out);
}

Color material_atternuation(void *p)
{
    Material *material = (Material*)p;
    return (*material->vtbl->attenuation)(material);
}
