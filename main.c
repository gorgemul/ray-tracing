#include "vec3.h"
#include "color.h"
#include "ray.h"
#include <stdio.h>

Color get_ray_color(Ray *ray)
{
    Vec3 unit_direction = vec3_unit_vector(&ray->direction); // [-1, 1]
    double a = 0.5 * (unit_direction.y + 1.0); // [0, 1]
    Color start_color = color_init(1.0, 1.0, 1.0);
    Color end_color = color_init(0.8, 0.2, 1.0);
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
    Vec3 half_viewport_u = vec3_div_scalar(1, &viewport_u, 2.0);
    Vec3 half_viewport_v = vec3_div_scalar(1, &viewport_v, 2.0);
    Vec3 pixel_delta_u = vec3_div_scalar(1, &viewport_u, (double)image_width);
    Vec3 pixel_delta_v = vec3_div_scalar(1, &viewport_v, (double)image_height);
    Vec3 half_pixel_delta_u = vec3_div_scalar(1, &pixel_delta_u, 2.0);
    Vec3 half_pixel_delta_v = vec3_div_scalar(1, &pixel_delta_v, 2.0);
    Vec3 viewport_top_left_corner = vec3_sub(3, &camera_center, &(Vec3){ 0, 0, focal_length }, &half_viewport_u, &half_viewport_v);
    Vec3 pixel_00 = vec3_add(2, &viewport_top_left_corner, &half_pixel_delta_u, &half_pixel_delta_v);

    printf("P3\n%d %d\n255\n", image_width, image_height);
    for (int h = 0; h < image_height; ++h) {
        for (int w = 0; w < image_width; ++w) {
            Vec3 delta_u = vec3_mul_scalar(1, &pixel_delta_u, (double)w);
            Vec3 delta_v = vec3_mul_scalar(1, &pixel_delta_v, (double)h);
            Vec3 pixel_center = vec3_add(2, &pixel_00, &delta_u, &delta_v);
            Vec3 direction = vec3_sub(1, &pixel_center, &camera_center);
            Color color = get_ray_color(&(Ray){ camera_center, direction });
            color_write(&color, stdout);
        }
    }
}
