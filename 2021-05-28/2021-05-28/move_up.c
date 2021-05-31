#include "elemtype.h"
#include "minheap.h"


void HeapMinMoveUpRec(Heap* h, int i) {
	if (i> 0 && ElemCompare(&h->data[i], &h->data[i / 2]) >= 0)
		return;
	ElemSwap(&h->data[i], &h->data[HeapParent(i)]);
	HeapMinMoveUpRec(h, i / 2);
}

