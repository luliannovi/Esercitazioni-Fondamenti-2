#include "elemtype.h"
#include "list.h"
#include <limits.h>
#include <stdlib.h>


Item* BucketSort(Item* l) {
	Item* tmp = l;
	int n = 0;
	int max ;
	int min ;
	GetMinMaxSize(l, &min, &max, &n);
	if (n == 0 || n == 1) {
		return l;
	}
	Item** v = malloc(n * sizeof(Item *));
	for (int i = 0; i < n; i++)
		v[i] = NULL;
	tmp = l;
	while (!ListIsEmpty(tmp)) {
		v[((n - 1) * ((int)tmp->value - min)) / (max - min)] = ListInsertBack(v[((n - 1) * ((int)tmp->value - min)) / (max - min)], ListGetHeadValue(tmp));
		
		tmp = ListGetTail(tmp);
	}
	for (int i = 0; i < n; i++) {
		v[i] = BucketSort(v[i]);
	}
	Item* ax=NULL;
	
	for (int i = 0; i < n; i++) {
		Item* p = v[i];
		while (!ListIsEmpty(p)) {
			ax = ListInsertBack(ax, ListGetHeadValue(p));
			p = ListGetTail(p);
		}
	}
	for (int i = 0; i < n; i++)
		ListDelete(v[i]);
	free(v);
	free(l);
	return ax;
}
/*
int main() {
	Item a;
	Item b;
	Item c;
	Item d;
	a.value = 7;
	b.value = 2;
	c.value = 5;
	d.value = 4;
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = NULL;
	Item * k = BucketSort(&a);
	return 0;
}*/