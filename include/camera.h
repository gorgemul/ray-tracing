#ifndef CAMERA_H_
#define CAMERA_H_

#include "vec3.h"
#include "shape.h"

typedef struct {
    int image_width;
    int image_height;
    int samples_per_pixel;
    int max_reflection;
    Point3 center;
    Point3 pixel_00; // top left first pixel
    Vec3 pixel_delta_u;
    Vec3 pixel_delta_v;
} Camera;

Camera camera_init(double image_ratio, int image_width, int samples_per_pixel, int max_reflection);
void camera_render(Camera *camera, Shape *world);

#endif // CAMERA_H_
