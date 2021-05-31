#include <stdlib.h>
#include <stdio.h>
#include "elemtype.h"
#include "list.h"

void ConcatenaNRec(Item* l, size_t v_size, Item** v, int index) {
	if (index == v_size)
		return;
	Item* tmp = l;
	while (tmp->next!=NULL) {
		tmp = ListGetTail(tmp);
	}
	if(v[index]!=NULL)
		tmp->next = v[index];
	ConcatenaNRec(l,v_size, v, index + 1);
}


Item* ConcatenaN(Item** v, size_t v_size) {
	if (v==NULL || v_size == 0)
		return NULL;
	Item* l=NULL;
	int init = -1;
	for (int i = 0; i < v_size; i++) {
		if (v[i] != NULL) {
			l = v[i];
			init = i;
			break;
		}
	}
	if (init == -1)
		return NULL;
	ConcatenaNRec(l,v_size, v, init +1);
	return l;
}

Item* ListCreateFromVector(const int* v, size_t v_size) {
	Item* list = ListCreateEmpty();
	for (size_t i = 0; i < v_size; ++i) {
		list = ListInsertBack(list, &v[i]);
	}
	return list;
}
/*
int main(void) {
	int v1[3] = { 1,2,3 };
	int v2[3] = { 3,2,1 };
	Item* a = ListCreateFromVector(v1, 3);
	Item* b = ListCreateFromVector(v2, 3);
	Item** v = malloc(3 * sizeof(Item*));
	v[0] = a;
	v[1] = NULL;
	v[2] = b;
	ConcatenaN(v, 3);
}*/