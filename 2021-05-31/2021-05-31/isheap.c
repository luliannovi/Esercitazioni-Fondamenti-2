#include "minheap.h"
#include "elemtype.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

bool ControlLevel(const Heap* h,int i, int livello, int totlivelli) {
	if (livello < totlivelli) {
		if (i >= h->size)
			return false;
		else {
			if (HeapLeft(i) >= h->size && (livello + 1) == totlivelli)
				return true;
			else if (HeapRight(i) >= h->size && (livello + 1) == totlivelli) {
				if (HeapLeft(i) < h->size) {
					return (ElemCompare(&h->data[i], &h->data[HeapLeft(i)]) <= 0);
				}
				else
					return true;
			}
			else if (HeapLeft(i) >= h->size || HeapRight(i) >= h->size)
				return false;
			else if (ElemCompare(&h->data[i], &h->data[HeapLeft(i)]) <= 0 && ElemCompare(&h->data[i], &h->data[HeapRight(i)]) <= 0) {
				return true && ControlLevel(h, HeapLeft(i), livello + 1, totlivelli) && ControlLevel(h, HeapRight(i), livello + 1, totlivelli);
			}
		}
	}
	else
		return true;
}


bool IsHeap(const Heap* h) {
	if (HeapIsEmpty(h))
		return false;
	if (h->size == 0)
		return true;
	int tot = (int)log2(h->size);
	if (tot > 1) {
		if (ElemCompare(&h->data[0], &h->data[HeapLeft(0)]) <= 0 && ElemCompare(&h->data[0], &h->data[HeapRight(0)]) <= 0) {
			return true && ControlLevel(h, HeapLeft(0), 1, tot) && ControlLevel(h, HeapRight(0), 1, tot);
		}
		else
			return false;
	}
	else
		return true;

}