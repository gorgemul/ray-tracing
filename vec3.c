#include "vec3.h"
#include <stddef.h>
#include <stdarg.h>
#include <math.h>

Vec3 vec3_add(Vec3 *vec, size_t n, ...)
{
    Vec3 result_vec = { vec->x, vec->y, vec->z };
    if (n == 0) return result_vec;
    va_list args;
    va_start(args, n);
    for (size_t i = 0; i < n; ++i) {
        Vec3 *current = va_arg(args, Vec3*);
        result_vec.x += current->x;
        result_vec.y += current->y;
        result_vec.z += current->z;
    }
    va_end(args);
    return result_vec;
}

Vec3 vec3_sub(Vec3 *vec, size_t n, ...)
{
    Vec3 result_vec = { vec->x, vec->y, vec->z };
    if (n == 0) return result_vec;
    va_list args;
    va_start(args, n);
    for (size_t i = 0; i < n; ++i) {
        Vec3 *current = va_arg(args, Vec3*);
        result_vec.x -= current->x;
        result_vec.y -= current->y;
        result_vec.z -= current->z;
    }
    va_end(args);
    return result_vec;
}

Vec3 vec3_mul(Vec3 *vec, size_t n, ...)
{
    Vec3 result_vec = { vec->x, vec->y, vec->z };
    if (n == 0) return result_vec;
    va_list args;
    va_start(args, n);
    for (size_t i = 0; i < n; ++i) {
        Vec3 *current = va_arg(args, Vec3*);
        result_vec.x *= current->x;
        result_vec.y *= current->y;
        result_vec.z *= current->z;
    }
    va_end(args);
    return result_vec;
}

Vec3 vec3_div(Vec3 *vec, size_t n, ...)
{
    Vec3 result_vec = { vec->x, vec->y, vec->z };
    if (n == 0) return result_vec;
    va_list args;
    va_start(args, n);
    for (size_t i = 0; i < n; ++i) {
        Vec3 *current = va_arg(args, Vec3*);
        result_vec.x /= current->x;
        result_vec.y /= current->y;
        result_vec.z /= current->z;
    }
    va_end(args);
    return result_vec;
}

Vec3 vec3_mul_scalar(Vec3 *vec, size_t n, ...)
{
    Vec3 result_vec = { vec->x, vec->y, vec->z };
    if (n == 0) return result_vec;
    va_list args;
    va_start(args, n);
    for (size_t i = 0; i < n; ++i) {
        double scalar = va_arg(args, double);
        result_vec.x *= scalar;
        result_vec.y *= scalar;
        result_vec.z *= scalar;
    }
    va_end(args);
    return result_vec;
}

Vec3 vec3_div_scalar(Vec3 *vec, size_t n, ...)
{
    Vec3 result_vec = { vec->x, vec->y, vec->z };
    if (n == 0) return result_vec;
    va_list args;
    va_start(args, n);
    for (size_t i = 0; i < n; ++i) {
        double scalar = va_arg(args, double);
        result_vec.x /= scalar;
        result_vec.y /= scalar;
        result_vec.z /= scalar;
    }
    va_end(args);
    return result_vec;
}

Vec3 vec3_neg(Vec3 *vec)
{
    return vec3_mul_scalar(vec, 1, -1.0);
}

Vec3 vec3_unit_vector(Vec3 *vec)
{
    return vec3_div_scalar(vec, 1, vec3_len(vec));
}

double vec3_squared_len(Vec3 *vec)
{
    return vec->x * vec->x + vec->y * vec->y + vec->z * vec->z;
}

double vec3_len(Vec3 *vec)
{
    return sqrt(vec3_squared_len(vec));
}

double vec3_dot(Vec3 *vec1, Vec3 *vec2)
{
    return vec1->x * vec2->x + vec1->y * vec2->y + vec1->z * vec2->z;
}

bool vec3_is_zero_vector(Vec3 *vec)
{
    double threadshold = 1e-7;
    return vec->x <= threadshold && vec->y <= threadshold && vec->z <= threadshold;
}
