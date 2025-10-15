#ifndef LAMBERTIAN_H_
#define LAMBERTIAN_H_

#include "material.h"
#include "color.h"

typedef struct {
    Material material;
} Lambertian;

Lambertian lambertian_init(Color albedo);

#endif // LAMBERTIAN_H_
