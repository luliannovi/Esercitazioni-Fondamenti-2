#include "vector.h"

int VectorFind(const Vector* v, const ElemType* e) {
	if (v != NULL && e != NULL) {
		for (size_t i = 0; i < v->size; i++) {
			int a = ElemCompare(&v->data[i], e);
			if(a==0)
				return (int)i;
		}
	}
	return -1;
}

