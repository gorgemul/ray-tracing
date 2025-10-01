#ifndef VEC3_H_
#define VEC3_H_

#include <stddef.h>

typedef struct {
    double x, y, z;
} Vec3;

typedef Vec3 Point3;

Vec3 vec3_add(size_t n, Vec3 *vec, ...);
Vec3 vec3_sub(size_t n, Vec3 *vec, ...);
Vec3 vec3_mul(size_t n, Vec3 *vec, ...);
Vec3 vec3_div(size_t n, Vec3 *vec, ...);
Vec3 vec3_mul_scalar(size_t n, Vec3 *vec, ...);
Vec3 vec3_div_scalar(size_t n, Vec3 *vec, ...);
Vec3 vec3_unit_vector(Vec3 *vec);
double vec3_len_squared(Vec3 *vec);
double vec3_len(Vec3 *vec);

#endif // VEC3_H_
