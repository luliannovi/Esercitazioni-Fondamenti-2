#include "elemtype.h"
#include "list.h"

Item* CreaDaMinori(const Item* i, int v) {
	if (ListIsEmpty(i))
		return NULL;
	ElemType a = v;
	Item* tmp = i;
	Item* ret = ListCreateEmpty();
	while (!ListIsEmpty(tmp)) {
		while ( !ListIsEmpty(tmp) && (ElemCompare(ListGetHeadValue(tmp), &a) > 0)) {
			tmp = ListGetTail(tmp);
		}
		if (ListIsEmpty(tmp))
			break;
		ret = ListInsertBack(ret, ListGetHeadValue(tmp));
		tmp = ListGetTail(tmp);
	}
	return ret;
}
/*
int main(void) {
	Item* a =ListCreateEmpty();
	ElemType b = 12;
	a = ListInsertBack(a, &b);
	b = 22;
	a = ListInsertBack(a, &b);
	b = 10;
	a = ListInsertBack(a, &b);
	b = 42;
	a = ListInsertBack(a, &b);
	CreaDaMinori(a, 5);
	return 0;
}*/