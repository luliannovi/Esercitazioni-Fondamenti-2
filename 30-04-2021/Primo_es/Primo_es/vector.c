#include "vector.h"
#include <stdlib.h>
#include <stdio.h>

Vector* VectorRead(const char* filename) {
	if (filename == NULL)
		return NULL;
	FILE* f = fopen(filename, "r");
	if (f == NULL)
		return NULL;
	Vector* res = malloc(sizeof(Vector));
	res->capacity = 1;
	res->size = 0;
	res->data = malloc(res->capacity*sizeof(ElemType));
	while (f != EOF) {
		if (res->size == res->capacity) {
			res->capacity *= 2;
			res->data = realloc(res->data,res->capacity * sizeof(ElemType));
		}
		if (ElemRead(f, &res->data[res->size]) != 1)
			break;
		res->size += 1;
	}
	fclose(f);
	return res;
}

void scambia(ElemType* a, ElemType* b) {
	ElemType tmp = *a;
	*a = *b;
	*b = tmp;
}

void BubbleSort(ElemType * v, size_t dim) {
	int i;
	bool ordinato = false;
	while (dim > 1 && !ordinato) {
		ordinato = true;
		for (i = 0; i < dim - 1; i++) {
			if (v[i] > v[i + 1]) {
				scambia(&v[i], &v[i + 1]);
				ordinato = false;
			}
		}
		dim--;
	}
}

Vector* VectorReadSorted(const char* filename) {
	if (filename == NULL)
		return NULL;
	FILE* f = fopen(filename, "r");
	if (f == NULL)
		return NULL;
	Vector* res = malloc(sizeof(Vector));
	res->capacity = 1;
	res->size = 0;
	res->data = malloc(res->capacity * sizeof(ElemType));
	while (f != EOF) {
		if (res->size == res->capacity) {
			res->capacity *= 2;
			res->data = realloc(res->data, res->capacity * sizeof(ElemType));
		}
		if (ElemRead(f, &res->data[res->size]) != 1)
			break;
		res->size += 1;
	}
	fclose(f);

	BubbleSort(res->data,res->size);

	return res;
}
/*
int main(void) {
	VectorRead("input_int_01.txt");
	VectorReadSorted("input_int_01.txt");
	return 0;
}*/