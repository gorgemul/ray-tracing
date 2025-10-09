#include "vec3.h"
#include "color.h"
#include "ray.h"
#include "sphere.h"
#include <stdio.h>

Color get_ray_color(Ray *ray)
{
    Sphere front_sphere = { .center = { 0.0, 0.0, -1.0 }, .radius = 0.5 }; // in front of camera
    double t = sphere_hit(&front_sphere, ray);
    if (t > 0.0) {
        Point3 hit_point = ray_at(ray, t);
        Vec3 CP = vec3_sub(&hit_point, 1, &front_sphere.center);
        Vec3 N = vec3_unit_vector(&CP);
        return color_init((N.x + 1 ) * 0.5, (N.y + 1) * 0.5, (N.z + 1) * 0.5);
    }
    Vec3 unit_direction = vec3_unit_vector(&ray->direction); // [-1, 1]
    double a = 0.5 * (unit_direction.y + 1.0); // [0, 1]
    Color start_color = color_init(1.0, 1.0, 1.0);
    Color end_color = color_init(0.5, 0.5, 1.0);
    double r = (1.0 - a) * start_color.x + end_color.x * a;
    double g = (1.0 - a) * start_color.y + end_color.y * a;
    double b = (1.0 - a) * start_color.z + end_color.z * a;
    return color_init(r, g, b);
}

int main(void)
{
    double image_ratio = 16.0 / 9.0;
    int image_width = 400;
    int image_height = (int)(image_width / image_ratio);
    if (image_height < 1) image_height = 1;
    double focal_length = 1.0;
    double viewport_height = 2.0;
    double viewport_width = viewport_height * ((double)image_width / image_height);
    Point3 camera_center = { 0, 0, 0 };
    Vec3 viewport_u = { viewport_width, 0, 0 };
    Vec3 viewport_v = { 0, -viewport_height, 0 };
    Vec3 half_viewport_u = vec3_div_scalar(&viewport_u, 1, 2.0);
    Vec3 half_viewport_v = vec3_div_scalar(&viewport_v, 1, 2.0);
    Vec3 pixel_delta_u = vec3_div_scalar(&viewport_u, 1, (double)image_width);
    Vec3 pixel_delta_v = vec3_div_scalar(&viewport_v, 1, (double)image_height);
    Vec3 half_pixel_delta_u = vec3_div_scalar(&pixel_delta_u, 1, 2.0);
    Vec3 half_pixel_delta_v = vec3_div_scalar(&pixel_delta_v, 1, 2.0);
    Vec3 viewport_top_left_corner = vec3_sub(&camera_center, 3, &(Vec3){ 0, 0, focal_length }, &half_viewport_u, &half_viewport_v);
    Vec3 pixel_00 = vec3_add(&viewport_top_left_corner, 2, &half_pixel_delta_u, &half_pixel_delta_v);

    printf("P3\n%d %d\n255\n", image_width, image_height);
    for (int h = 0; h < image_height; ++h) {
        for (int w = 0; w < image_width; ++w) {
            Vec3 delta_u = vec3_mul_scalar(&pixel_delta_u, 1, (double)w);
            Vec3 delta_v = vec3_mul_scalar(&pixel_delta_v, 1, (double)h);
            Vec3 pixel_center = vec3_add(&pixel_00, 2, &delta_u, &delta_v);
            Vec3 direction = vec3_sub(&pixel_center, 1, &camera_center);
            Color color = get_ray_color(&(Ray){ camera_center, direction });
            color_write(&color, stdout);
        }
    }
}
