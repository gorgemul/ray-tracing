#ifndef METAL_H_
#define METAL_H_

#include "material.h"
#include "color.h"

typedef struct {
    Material material;
} Metal;

Metal metal_init(Color albedo);

#endif // METAL_H_
