#ifndef VECTOR_H
#define VECTOR_H

#include "elemtype.h"

typedef struct {
    size_t capacity;
    size_t size;
    ElemType* data;
} Vector;

void VectorSort(Vector* v);


#endif // !VECTOR_H
