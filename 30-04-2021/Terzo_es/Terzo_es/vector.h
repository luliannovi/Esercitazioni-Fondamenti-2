#ifndef VECTOR_H
#define VECTOR_H

#include "elemtype.h"

typedef struct {
    size_t capacity;
    size_t size;
    ElemType* data;
} Vector;


int VectorFind(const Vector* v, const ElemType* e);

#endif