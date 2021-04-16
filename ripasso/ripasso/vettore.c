#include "vettore.h"
#include <stdlib.h>
void Push(struct vettore* v, int d) {
	if (v != NULL) {
		v->size = v->size + 1;
		v->data = realloc(v->data, (v->size) * sizeof(int));
		v->data[v->size-1] = d;
	}
}


int Pop(struct vettore* v) {
	if (v != NULL) {
		int ret = v->data[0];
		for (size_t c = 1; c < v->size; c++) {
			v->data[c - 1] = v->data[c];
		}
		v->size = v->size - 1;
		v->data = realloc(v->data, v->size*sizeof(int));
		return ret;
	}
}
