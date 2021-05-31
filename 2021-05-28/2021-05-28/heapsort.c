#include "elemtype.h"
#include "minheap.h"


void HeapMinHeapsort(Heap* h) {
	if (HeapIsEmpty(h) || h->size == 1)
		return;
	size_t len = h->size;
	for (int i = 0; i < len - 1; i++) {
		ElemType e = h->data[0];
		ElemSwap(&h->data[0], &h->data[h->size - 1]);
		h->size--;
		HeapMinMoveDown(h, 0);
	}
	h->size = len;
	return;

}

/*
int main(void) {
	Heap* h = HeapCreateEmpty();
	h->size = 6;
	h->data = malloc(6 * sizeof(ElemType));
	for (int i = 0; i < 6; i++) {
		h->data[i] = i;
	}
	ElemType a = 0;
	HeapMinHeapsort(h);
	return 0;
}*/