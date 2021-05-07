#include "elemtype.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

const ElemType* MaxElement(const Item* i) {
	if (ListIsEmpty(i))
		return NULL;
	const Item* max;
	const Item* tmp = i;
	while (!ListIsEmpty(tmp)) {
		if (ElemCompare(ListGetHeadValue(tmp), max) > 0) {
			max = tmp;
			tmp = ListGetTail(tmp);
		}
		else {
			tmp = ListGetTail(tmp);
		}
	}
	return ListGetHeadValue(max);
}
/*
int main(void) {
	Item* l = ListLoad("data_00.txt");
	MaxElement(l);
	return 0;
}*/