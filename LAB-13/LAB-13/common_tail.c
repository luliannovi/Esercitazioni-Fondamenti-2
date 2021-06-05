#include "elemtype.h"
#include "list.h"
#include <stdlib.h>

Item* MaxCommon(const Item* i1, const Item* i2,int * h) {
	Item* a = i1;
	int l = 0;
	Item* tmp2 = NULL;
	while (a != NULL) {
		if (i2 == a) {
			tmp2 = a;
			while (a != NULL) {
				l++;
				a = ListGetTail(a);
			}
			break;
		}
		a = ListGetTail(a);
	}
	if (l > 0) {
		*h = l;
		return tmp2;
	}
	return NULL;
}

const Item* CommonTail(const Item* i1, const Item* i2) {
	if (i1 == i2)
		return i1;
	if (ListIsEmpty(i1) || ListIsEmpty(i2))
		return NULL;
	Item* tmp = NULL;
	Item* az = i2;
	int h = 0;
	while (az != NULL) {
		tmp = MaxCommon(i1, az, &h);
		if ( h> 0) {
			return tmp;
		}
		az = ListGetTail(az);
	}
	return tmp;
}

Item* ListCreateFromVector(const int* v, size_t v_size) {
	Item* list = ListCreateEmpty();
	for (size_t i = 0; i < v_size; ++i) {
		list = ListInsertBack(list, &v[i]);
	}
	return list;
}
/*
int main() {
	int v[5] = { 1,2,3,4,5 };
	Item* a = ListCreateFromVector(v, 5);
	int m[1] = { 3 };
	Item* b = ListCreateFromVector(m, 1);
	b->next = a;
	CommonTail(b,a);
}*/
