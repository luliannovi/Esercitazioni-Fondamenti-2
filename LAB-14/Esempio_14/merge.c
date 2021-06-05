#include "minheap.h"
#include "elemtype.h"
#include <stdlib.h>
#include <stdio.h>

Heap* MergeHeap(const Heap* h1, const Heap* h2) {
	if (HeapIsEmpty(h1) && HeapIsEmpty(h2))
		return HeapCreateEmpty();
	else if (HeapIsEmpty(h2)) {
		Heap* ret = HeapCreateEmpty();
		for (int i = 0; i < h1->size; i++) {
			HeapMinInsertNode(ret, &h1->data[i]);
		}
		return ret;
	}
	else if (HeapIsEmpty(h1)) {
		Heap* ret = HeapCreateEmpty();
		for (int i = 0; i < h2->size; i++) {
			HeapMinInsertNode(ret, &h2->data[i]);
		}
		return ret;
	}

	Heap* ret = HeapCreateEmpty();
	for (int i = 0; i < h1->size; i++) {
		HeapMinInsertNode(ret, &h1->data[i]);
	}
	for (int i = 0; i < h2->size; i++) {
		HeapMinInsertNode(ret, &h2->data[i]);
	}
	return ret;

}