#include "vec3.h"

Vec3 vec3_add(Vec3 *vec1, Vec3 *vec2)
{
    return (Vec3){vec1->x + vec2->x, vec1->y + vec2->y, vec1->z + vec2->z};
}

Vec3 vec3_sub(Vec3 *vec1, Vec3 *vec2)
{
    return (Vec3){vec1->x - vec2->x, vec1->y - vec2->y, vec1->z - vec2->z};
}

Vec3 vec3_mul(Vec3 *vec1, Vec3 *vec2)
{
    return (Vec3){vec1->x * vec2->x, vec1->y * vec2->y, vec1->z * vec2->z};
}

Vec3 vec3_div(Vec3 *vec1, Vec3 *vec2)
{
    return (Vec3){vec1->x / vec2->x, vec1->y / vec2->y, vec1->z / vec2->z};
}
