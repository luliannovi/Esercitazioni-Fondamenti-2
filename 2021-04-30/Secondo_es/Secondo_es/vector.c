#include "vector.h"

void BubbleSort(ElemType* e, size_t dim) {
	bool ordinato = false;
	int i;
	while (dim > 1 && !ordinato) {
		ordinato = true;
		for (i = 0; i < dim - 1; i++) {
			if (ElemCompare(&e[i], &e[i + 1])>0) {
				ElemSwap(&e[i], &e[i + 1]);
				ordinato = false;
			}
		}
		dim--;
	}
}


void VectorSort(Vector* v) {
	if (v == NULL)
		return;
	BubbleSort(v->data, v->size);
}

