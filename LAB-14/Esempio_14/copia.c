#include "list.h"
#include "elemtype.h"

Item* CopiaDaN(const Item* i, int n) {
	if (ListIsEmpty(i) || n<=0)
		return NULL;
	Item* tmp = i;
	Item* ret = ListCreateEmpty();
	for (int i = 1; i < n && tmp != NULL; i++) {
		tmp = ListGetTail(tmp);
	}
	if (tmp == NULL)
		return NULL;
	else {
		while (tmp != NULL) {
			ret = ListInsertBack(ret, ListGetHeadValue(tmp));
			tmp = ListGetTail(tmp);
		}
	}
	return ret;
}