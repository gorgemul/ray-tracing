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
    Camera camera = camera_init(16.0 / 9.0, 400, 100);
    ShapeVector *world = shape_vector_init(5);
    Sphere sphere1 = sphere_init((Point3){ 0.0, 0.0, -1.0 }, 0.5);
    Sphere sphere2 = sphere_init((Point3){ 0.0, -100.5, -1.0 }, 100);
    shape_vector_push(world, &sphere1);
    shape_vector_push(world, &sphere2);
    camera_render(&camera, (Shape*)world);
    shape_vector_destroy(world);
}
