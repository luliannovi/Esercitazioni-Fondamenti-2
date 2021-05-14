#define _CRT_SECURE_NO_WARNINGS
#include "elemtype.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

const ElemType* Find(const Item* i, const char* name) {
	if (i == NULL)
		return NULL;
	ElemType a;
	strcpy(a.name, name);
	if (ElemCompare(&(i->value), &a) == 0) {
		ElemDelete(&a);
		return &(i->value);
	}
	return Find(i->next, name);
}


Item* Delete(Item* i, const char* name) {
	if (name == NULL)
		return i;
	if (i == NULL)
		return i;
	
	Item* a;
	if (strcmp(i->value.name,name)==0) {
		a = ListGetTail(i);
		ElemDelete(&i->value);
		free(i);
		return a;
	}
	
	
	a = i;
	Item* k ;
	k = i;
	i = ListGetTail(i);
	while (!ListIsEmpty(i)) {
		if (strcmp(i->value.name, name)==0) {
			k->next = i->next;
			ElemDelete(&i->value);
			free(i);
			break;
		}
		k = i;
		i = ListGetTail(i);
	}
	return a;
}

int ListDim(Item* i) {
	int len = 0;
	while (!ListIsEmpty(i)) {
		len++;
		i = ListGetTail(i);
	}
	return len;
}


Item* Sort(Item* i) {
	if (i == NULL || i->next==NULL)
		return i;
	bool ordinato = false;
	Item* a = i;
	int ltot = ListDim(i);
	int dim = ltot;
	while (dim>0 && !ordinato) {
		
		ordinato = true;
		Item* k;
		int len = 0;
		do {
			k = ListGetTail(i);
			if (k == NULL)
				break;
			if (ElemCompare(ListGetHeadValue(i), ListGetHeadValue(k)) >= 0) {
				ElemType tmp = k->value;
				k->value = i->value;
				i->value = tmp;
				
				ordinato = false;
			}
			i = k;
			len++;
		} while (len<ltot);
		i = a;
		dim--;
	}
	return a;
}


Item* Filtra(const Item* i, const char* city) {
	if (i == NULL || city==NULL)
		return NULL;
	Item* new = ListCreateEmpty();
	//Item* a = i;
	while (!ListIsEmpty(i)) {
		if (strcmp(city, ListGetHeadValue(i)->city) == 0) {
			new = ListInsertBack(new, ListGetHeadValue(i));
		}
		i = ListGetTail(i);
	}
	return new;
}


Item* Reverse(const Item* i) {
	if (i == NULL)
		return NULL;
	Item* new = ListCreateEmpty();
	while (!ListIsEmpty(i)) {
		new = ListInsertHead(ListGetHeadValue(i), new);
		i = ListGetTail(i);
	}
	return new;
}

Item* Append(const Item* i1, const Item* i2) {
	Item* new = ListCreateEmpty();
	
	if (i1 == NULL) {
		while (!ListIsEmpty(i2)) {
			new = ListInsertBack(new, ListGetHeadValue(i2));
			i2 = ListGetTail(i2);
		}
		return new;
	}
	if (i2 == NULL) {
		while (!ListIsEmpty(i1)) {
			new = ListInsertBack(new, ListGetHeadValue(i1));
			i1 = ListGetTail(i1);
		}
		return new;
	}
	
	
	while (!ListIsEmpty(i1)) {
		new = ListInsertBack(new, ListGetHeadValue(i1));
		i1 = ListGetTail(i1);
	}
	while (!ListIsEmpty(i2)) {
		new = ListInsertBack(new, ListGetHeadValue(i2));
		i2 = ListGetTail(i2);
	}
	return new;
}

Item* AppendMod(Item* i1, Item* i2) {
	Item* a = i1;
	while (!ListIsEmpty(i1)) {
		i1 = ListGetTail(i1);
	}
	i1->next = i2;
	i1 = a;
	return i1;
}