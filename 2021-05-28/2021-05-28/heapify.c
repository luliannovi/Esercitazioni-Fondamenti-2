#include "elemtype.h"
#include "minheap.h"


Heap* HeapMinHeapify(const ElemType* v, size_t v_size) {
	if (v == NULL)
		return HeapCreateEmpty();
	Heap* ret = HeapCreateEmpty();
	for (size_t i = 0; i < v_size; i++) {
		HeapMinInsertNode(ret, &v[i]);
	}
	return ret;
}

