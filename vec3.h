#ifndef VEC3_H_
#define VEC3_H_

typedef struct {
    double x, y, z;
} Vec3;

Vec3 vec3_add(Vec3 *vec1, Vec3 *vec2);
Vec3 vec3_sub(Vec3 *vec1, Vec3 *vec2);
Vec3 vec3_mul(Vec3 *vec1, Vec3 *vec2);
Vec3 vec3_div(Vec3 *vec1, Vec3 *vec2);

#endif // VEC3_H_
