#include "vec3.h"
#include "color.h"
#include "ray.h"
#include "sphere.h"
#include "shape.h"
#include "shape_vector.h"
#include "camera.h"
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    Camera camera = camera_init(16.0 / 9.0, 1920, 100, 30);
    ShapeVector *world = shape_vector_init(5);
    Sphere sphere1 = sphere_init((Point3){ -0.6, 0.0, -1.0 }, 0.3);
    Sphere sphere2 = sphere_init((Point3){ 0.0, 0.0, -1.0 }, 0.3);
    Sphere sphere3 = sphere_init((Point3){ 0.6, 0.0, -1.0 }, 0.3);
    Sphere sphere4 = sphere_init((Point3){ -0.3, -0.2, -0.9 }, 0.1);
    Sphere sphere5 = sphere_init((Point3){ 0.3, -0.2, -0.9 }, 0.1);
    Sphere ground = sphere_init((Point3){ 0.0, -30.3, -1.0 }, 30);
    shape_vector_push(world, &sphere1);
    shape_vector_push(world, &sphere2);
    shape_vector_push(world, &sphere3);
    shape_vector_push(world, &sphere4);
    shape_vector_push(world, &sphere5);
    shape_vector_push(world, &ground);
    camera_render(&camera, (Shape*)world);
    shape_vector_destroy(world);
}
