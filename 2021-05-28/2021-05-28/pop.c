#include "elemtype.h"
#include "minheap.h"
#include <stdlib.h>

bool HeapMinPop(Heap* h, ElemType* e) {
	if (HeapIsEmpty(h))
		return false;
	*e = ElemCopy(&h->data[0]);

	h->data[0] = ElemCopy(&h->data[h->size - 1]);
	h->size = h->size - 1;
	h->data = realloc(h->data, h->size * sizeof(ElemType));
	HeapMinMoveDown(h, 0);
	return true;
}
/*
int main(void) {
	Heap* h = HeapCreateEmpty();
	h->size = 6;
	h->data = malloc(6 * sizeof(ElemType));
	for (int i = 0; i < 6; i++) {
		h->data[i] = i + 1;
	}
	ElemType a = 0;
	HeapMinPop(h, &a);
	return 0;
}*/