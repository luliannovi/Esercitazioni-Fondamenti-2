#include "elemtype.h"
#include "minheap.h"

void HeapMinMoveDownRec(Heap* h, int i) {
	if (i >= 0 && i < h->size) {
		if (ElemCompare(&h->data[i], &h->data[HeapLeft(i)]) > 0) {
			ElemSwap(&h->data[i], &h->data[HeapLeft(i)]);
			HeapMinMoveDownRec(h, HeapLeft(i));
		}
		else if (ElemCompare(&h->data[i], &h->data[HeapRight(i)]) > 0) {
			ElemSwap(&h->data[i], &h->data[HeapRight(i)]);
			HeapMinMoveDownRec(h, HeapRight(i));
		}
		else
			return;
	}
}