#include "shape_vector.h"
#include "interval.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static bool shape_vector_hit(Shape *shape, Ray *ray, Interval *interval, HitRecord *record)
{
    ShapeVector *sv = (ShapeVector*)shape;
    double max = interval->max;
    bool hit_once = false;

    for (size_t i = 0; i < sv->len; ++i) {
        if (shape_hit(sv->list[i], ray, &(Interval){ interval->min, max }, record)) {
            hit_once = true;
            max = record->ray_t;
        }
    }
    return hit_once;
}

ShapeVector *shape_vector_init(size_t cap)
{
    ShapeVector *sv = malloc(sizeof(*sv));
    if (!sv) {
        fprintf(stderr, "ERROR: shape_vector_init sv malloc fail\n");
        exit(1);
    }
    Shape **list = malloc(sizeof(*list) * cap);
    if (!list) {
        fprintf(stderr, "ERROR: shape_vector_init list malloc fail\n");
        exit(1);
    }
    static struct ShapeVTable vtbl = { .hit = &shape_vector_hit };
    sv->super = shape_init(&vtbl);
    sv->list = list;
    sv->len = 0;
    sv->cap = cap;
    return sv;
}

void shape_vector_push(ShapeVector *sv, void *item)
{
    Shape *shape = (Shape*)item;
    if (sv->len == sv->cap) {
        sv->cap *= 2;
        Shape **new_list = realloc(sv->list, sizeof(*new_list) * sv->cap);
        if (!new_list) {
            fprintf(stderr, "ERROR: shape_vector_push realloc fail\n");
            exit(1);
        }
        sv->list = new_list;
    }
    sv->list[sv->len++] = shape;
}

void shape_vector_destroy(ShapeVector *sv)
{
    free(sv->list);
    free(sv);
}
