#include "elemtype.h"
#include "list.h"
#include <stdlib.h>
#include <stdio.h>

int IsMember(const ElemType* e, Item* i) {
	while (!ListIsEmpty(i)) {
		if (ElemCompare(e, ListGetHeadValue(i)) == 0) {
			return 0;
		}
		i = ListGetTail(i);
	}
	return 1;
}


Item* Diff(const Item* i1, const Item* i2) {
	if (i1 == NULL)
		return NULL;
	Item* ret = ListCreateEmpty();
	
	const Item* tmp1 = i1;
	const Item* tmp2 = i2;
	while (!ListIsEmpty(tmp1)) {
		if (IsMember(ListGetHeadValue(tmp1), tmp2)==1) {
			ret = ListInsertBack(ret, ListGetHeadValue(tmp1));
			tmp1 = ListGetTail(tmp1);
			tmp2 = i2;
		}
		else {
			tmp1 = ListGetTail(tmp1);
			tmp2 = i2;
		}
	}
	return ret;
}
