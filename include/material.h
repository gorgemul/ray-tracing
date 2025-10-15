#ifndef MATERIAL_H_
#define MATERIAL_H_

#include "ray.h"
#include "color.h"
#include <stdbool.h>

struct HitRecord;
struct MaterialVTable;

typedef struct {
    struct MaterialVTable *vtbl;
    Color albedo;
} Material;

struct MaterialVTable {
    bool (*scatter)(Material *material, Ray *ray_in, struct HitRecord *record, Color *attenuation, Ray *ray_out);
    Color (*attenuation)(Material *material); // default function don't need to register
};

Material material_init(struct MaterialVTable *init_vtbl, Color albedo);
bool material_scatter(void *p, Ray *ray_in, struct HitRecord *record, Color *attenuation, Ray *ray_out);
Color material_atternuation(void *p);

#endif // MATERIAL_H_
