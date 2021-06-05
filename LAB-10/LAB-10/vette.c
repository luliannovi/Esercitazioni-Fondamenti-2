#include "elemtype.h"
#include "list.h"

bool IsVetta(Item* i, ElemType* a) {
	Item* tmp = i;
	while (!ListIsEmpty(tmp)) {
		if (ElemCompare(a, ListGetHeadValue(tmp)) <= 0) {
			return false;
		}
		tmp = ListGetTail(tmp);
	}
	return true;
}


int ContaVette(const Item* i) {
	if (ListIsEmpty(i))
		return 0;
	int vette = 0;
	Item* tmp = i;
	while (!ListIsEmpty(tmp)) {
		if (IsVetta(ListGetTail(tmp), ListGetHeadValue(tmp))) {
			vette+=1;
		}

		tmp = ListGetTail(tmp);
	}
	return vette;
}
/*
int main(void) {
	Item a;
	a.value = 4;
	Item b;
	b.value = 5;
	Item c;
	c.value = 2;
	Item d;
	d.value = 7;
	d.next = &c;
	c.next = &b;
	b.next = &a;
	a.next = NULL;
	ContaVette(&d);
}*/