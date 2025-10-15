#ifndef VEC3_H_
#define VEC3_H_

#include <stddef.h>
#include <stdbool.h>

typedef struct {
    double x, y, z;
} Vec3;

typedef Vec3 Point3;

Vec3 vec3_add(Vec3 *vec, size_t n, ...);
Vec3 vec3_sub(Vec3 *vec, size_t n, ...);
Vec3 vec3_mul(Vec3 *vec, size_t n, ...);
Vec3 vec3_div(Vec3 *vec, size_t n, ...);
Vec3 vec3_mul_scalar(Vec3 *vec, size_t n, ...);
Vec3 vec3_div_scalar(Vec3 *vec, size_t n, ...);
Vec3 vec3_neg(Vec3 *vec);
Vec3 vec3_unit_vector(Vec3 *vec);
double vec3_squared_len(Vec3 *vec);
double vec3_len(Vec3 *vec);
double vec3_dot(Vec3 *vec1, Vec3 *vec2);
bool vec3_is_zero_vector(Vec3 *vec);

#endif // VEC3_H_
