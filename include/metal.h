#ifndef METAL_H_
#define METAL_H_

#include "material.h"
#include "color.h"

typedef struct {
    Material material;
    double fuzzy_rate;
} Metal;

Metal metal_init(Color albedo, double fuzzy_rate);

#endif // METAL_H_
