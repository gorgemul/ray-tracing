#include "vec3.h"
#include <stddef.h>
#include <stdarg.h>
#include <math.h>

Vec3 vec3_add(size_t n, Vec3 *vec, ...)
{
    Vec3 result_vec = { vec->x, vec->y, vec->z };
    if (n == 0) return result_vec;
    va_list args;
    va_start(args, vec);
    for (size_t i = 0; i < n; ++i) {
        Vec3 *current = va_arg(args, Vec3*);
        result_vec.x += current->x;
        result_vec.y += current->y;
        result_vec.z += current->z;
    }
    va_end(args);
    return result_vec;
}

Vec3 vec3_sub(size_t n, Vec3 *vec, ...)
{
    Vec3 result_vec = { vec->x, vec->y, vec->z };
    if (n == 0) return result_vec;
    va_list args;
    va_start(args, vec);
    for (size_t i = 0; i < n; ++i) {
        Vec3 *current = va_arg(args, Vec3*);
        result_vec.x -= current->x;
        result_vec.y -= current->y;
        result_vec.z -= current->z;
    }
    va_end(args);
    return result_vec;
}

Vec3 vec3_mul(size_t n, Vec3 *vec, ...)
{
    Vec3 result_vec = { vec->x, vec->y, vec->z };
    if (n == 0) return result_vec;
    va_list args;
    va_start(args, vec);
    for (size_t i = 0; i < n; ++i) {
        Vec3 *current = va_arg(args, Vec3*);
        result_vec.x *= current->x;
        result_vec.y *= current->y;
        result_vec.z *= current->z;
    }
    va_end(args);
    return result_vec;
}

Vec3 vec3_div(size_t n, Vec3 *vec, ...)
{
    Vec3 result_vec = { vec->x, vec->y, vec->z };
    if (n == 0) return result_vec;
    va_list args;
    va_start(args, vec);
    for (size_t i = 0; i < n; ++i) {
        Vec3 *current = va_arg(args, Vec3*);
        result_vec.x /= current->x;
        result_vec.y /= current->y;
        result_vec.z /= current->z;
    }
    va_end(args);
    return result_vec;
}

Vec3 vec3_mul_scalar(size_t n, Vec3 *vec, ...)
{
    Vec3 result_vec = { vec->x, vec->y, vec->z };
    if (n == 0) return result_vec;
    va_list args;
    va_start(args, vec);
    for (size_t i = 0; i < n; ++i) {
        double scalar = va_arg(args, double);
        result_vec.x *= scalar;
        result_vec.y *= scalar;
        result_vec.z *= scalar;
    }
    va_end(args);
    return result_vec;
}

Vec3 vec3_div_scalar(size_t n, Vec3 *vec, ...)
{
    Vec3 result_vec = { vec->x, vec->y, vec->z };
    if (n == 0) return result_vec;
    va_list args;
    va_start(args, vec);
    for (size_t i = 0; i < n; ++i) {
        double scalar = va_arg(args, double);
        result_vec.x /= scalar;
        result_vec.y /= scalar;
        result_vec.z /= scalar;
    }
    va_end(args);
    return result_vec;
}

Vec3 vec3_unit_vector(Vec3 *vec)
{
    return vec3_div_scalar(1, vec, vec3_len(vec));
}

double vec3_len_squared(Vec3 *vec)
{
    return vec->x * vec->x + vec->y * vec->y + vec->z * vec->z;
}

double vec3_len(Vec3 *vec)
{
    return sqrt(vec3_len_squared(vec));
}
