#include "list.h"
#include "elemtype.h"

Item* ElementiPariRec(const Item* item, Item* ret, int i) {
	if (ListIsEmpty(item))
		return ret;
	if (i%2 != 0)
		ret = ElementiPariRec(ListGetTail(item), ret, i + 1);
	else {
		ret = ListInsertBack(ret, ListGetHeadValue(item));
		ret = ElementiPariRec(ListGetTail(item), ret, i + 1);
	}
	return ret;
}


Item* ElementiPari(const Item* i) {
	if (ListIsEmpty(i))
		return ListCreateEmpty();
	Item* ret = ListCreateEmpty();
	ret = ElementiPariRec(i, ret, 0);
	return ret;
}