#include "vec3.h"
#include "color.h"
#include "ray.h"
#include "sphere.h"
#include "shape.h"
#include "shape_vector.h"
#include "camera.h"
#include "lambertian.h"
#include "metal.h"
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    Camera camera = camera_init(16.0 / 9.0, 1920, 100, 30);
    ShapeVector *world = shape_vector_init(10);
    Lambertian ground_material = lambertian_init(color_init(0.8, 0.8, 0.0));
    Lambertian lambertian = lambertian_init(color_init(0.3, 0.4, 0.5));
    Metal smooth_metal = metal_init(color_init(0.8, 0.8, 0.8), 0.0); 
    Metal fuzzy_metal = metal_init(color_init(0.8, 0.8, 0.8), 0.5); 
    Sphere ground = sphere_init(&ground_material, (Point3){ 0.0, -20.4, -1.0 }, 20.0);
    Sphere sphere1 = sphere_init(&lambertian, (Point3){ -0.8, 0.0, -1.0 }, 0.4);
    Sphere sphere2 = sphere_init(&smooth_metal, (Point3){ 0.0, 0.0, -1.0 }, 0.4);
    Sphere sphere3 = sphere_init(&fuzzy_metal, (Point3){ 0.8, 0.0, -1.0 }, 0.4);
    Sphere sphere4 = sphere_init(&smooth_metal, (Point3){ -0.4, -0.3, -0.6 }, 0.1);
    Sphere sphere5 = sphere_init(&fuzzy_metal, (Point3){ 0.4, -0.3, -0.6 }, 0.1);
    Sphere sphere6 = sphere_init(&lambertian, (Point3){ -0.1, -0.3, -0.6 }, 0.1);
    Sphere sphere7 = sphere_init(&lambertian, (Point3){ 0.1, -0.3, -0.6 }, 0.1);
    shape_vector_push(world, &ground);
    shape_vector_push(world, &sphere1);
    shape_vector_push(world, &sphere2);
    shape_vector_push(world, &sphere3);
    shape_vector_push(world, &sphere4);
    shape_vector_push(world, &sphere5);
    shape_vector_push(world, &sphere6);
    shape_vector_push(world, &sphere7);
    camera_render(&camera, (Shape*)world);
    shape_vector_destroy(world);
}
