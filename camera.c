#include "camera.h"
#include "color.h"
#include "interval.h"
#include "common.h"

Color intersect(Ray *ray, Shape *world)
{
    HitRecord record;
    if (shape_hit(world, ray, &(Interval){ 0, INFINITY }, &record))
        return color_init((record.normal.x + 1 ) * 0.5, (record.normal.y + 1) * 0.5, (record.normal.z + 1) * 0.5);
    Vec3 unit_direction = vec3_unit_vector(&ray->direction);
    double a = 0.5 * (unit_direction.x + 1.0);
    Color start_color = color_init(1.0, 1.0, 1.0);
    Color end_color = color_init(0.5, 0.5, 1.0);
    double r = (1.0 - a) * start_color.x + end_color.x * a;
    double g = (1.0 - a) * start_color.y + end_color.y * a;
    double b = (1.0 - a) * start_color.z + end_color.z * a;
    return color_init(r, g, b);
}

Camera camera_init(double image_ratio, int image_width, int samples_per_pixel)
{
    int image_height = (int)(image_width / image_ratio);
    if (image_height < 1) image_height = 1;
    Point3 camera_center = { 0.0, 0.0, 0.0 };
    double focal_len = 1.0;
    double viewport_height = 2.0;
    double viewport_width = viewport_height * ((double)image_width / image_height);
    Vec3 viewport_u = { viewport_width, 0.0, 0.0 };
    Vec3 viewport_v = { 0.0, -viewport_height, 0.0 };
    Vec3 half_viewport_u = vec3_div_scalar(&viewport_u, 1, 2.0);
    Vec3 half_viewport_v = vec3_div_scalar(&viewport_v, 1, 2.0);
    Vec3 pixel_delta_u = vec3_div_scalar(&viewport_u, 1, (double)image_width);
    Vec3 pixel_delta_v = vec3_div_scalar(&viewport_v, 1, (double)image_height);
    Vec3 half_pixel_delta_u = vec3_div_scalar(&pixel_delta_u, 1, 2.0);
    Vec3 half_pixel_delta_v = vec3_div_scalar(&pixel_delta_v, 1, 2.0);
    Point3 top_left_corner = vec3_sub(&camera_center, 3, &(Vec3){ 0.0, 0.0, focal_len }, &half_viewport_u, &half_viewport_v);
    Point3 pixel_00 = vec3_add(&top_left_corner, 2, &half_pixel_delta_u, &half_pixel_delta_v);
    return (Camera){
        .image_width = image_width,
        .image_height = image_height,
        .center = camera_center,
        .pixel_00 = pixel_00,
        .pixel_delta_u = pixel_delta_u,
        .pixel_delta_v = pixel_delta_v,
        .samples_per_pixel = samples_per_pixel,
    };
}

void camera_render(Camera *camera, Shape *world)
{
    printf("P3\n%d %d\n255\n", camera->image_width, camera->image_height);
    for (int h = 0; h < camera->image_height; ++h) {
        for (int w = 0; w < camera->image_width; ++w) {
            double r = 0.0;
            double g = 0.0;
            double b = 0.0;
            Vec3 delta_u = vec3_mul_scalar(&camera->pixel_delta_u, 1, (double)w);
            Vec3 delta_v = vec3_mul_scalar(&camera->pixel_delta_v, 1, (double)h);
            for (int i = 0; i < camera->samples_per_pixel; ++i) {
                Vec3 offset_u = vec3_mul_scalar(&camera->pixel_delta_u, 1, rand_double() - 0.5);
                Vec3 offset_v = vec3_mul_scalar(&camera->pixel_delta_v, 1, rand_double() - 0.5);
                Vec3 u = vec3_add(&delta_u, 1, &offset_u);
                Vec3 v = vec3_add(&delta_v, 1, &offset_v);
                Point3 pixel = vec3_add(&camera->pixel_00, 2, &u, &v);
                Vec3 direction = vec3_sub(&pixel, 1, &camera->center);
                Ray ray = { .origin = camera->center, .direction = direction };
                Color color = intersect(&ray, world);
                r += color.x;
                g += color.y;
                b += color.z;
            }
            Color blend_color = color_init(r / camera->samples_per_pixel, g / camera->samples_per_pixel, b / camera->samples_per_pixel);
            color_write(&blend_color, stdout);
        }
    }
}
