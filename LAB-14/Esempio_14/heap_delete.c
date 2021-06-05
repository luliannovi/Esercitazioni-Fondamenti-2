#include "minheap.h"
#include "elemtype.h"

void HeapDeleteNode(Heap* h, int k) {
	if (k < 0 || k >= h->size || HeapIsEmpty(h))
		return;
	h->data[k] = h->data[h->size - 1];
	h->size -= 1;
	HeapMinMoveDown(h, k);
	return;


}