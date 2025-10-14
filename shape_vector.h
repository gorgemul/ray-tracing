#ifndef SHAPE_VECTOR_H_
#define SHAPE_VECTOR_H_

#include "shape.h"
#include <stddef.h>

typedef struct {
    Shape shape;
    Shape **list;
    size_t len;
    size_t cap;
} ShapeVector;

ShapeVector *shape_vector_init(size_t cap);
void shape_vector_push(ShapeVector *sv, void *item);
void shape_vector_destroy(ShapeVector *sv); // list item may be allocated in stack, only free list and shape_vector

#endif // SHAPE_VECTOR_H_
