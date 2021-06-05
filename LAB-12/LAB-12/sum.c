#include "list.h"
#include "elemtype.h"
#include <stdlib.h>
#include <stdio.h>

Item* ListCopy(const Item* i) {
	Item* list_copy = ListCreateEmpty(); // Creo una lista vuota (NULL pointer)

	// Itero tutti gli elementi della lista da copiare
	for (; !ListIsEmpty(i); i = ListGetTail(i)) {
		// Aggiungo l'elemento corrente della lista di input alla nuova lista
		// usando la primitiva ListInsertBack(), la quale si occupa di allocare
		// opportunamente la memoria e aggiornare i puntatori!
		list_copy = ListInsertBack(list_copy, ListGetHeadValue(i));
	}

	return list_copy;
}


Item * SumRec(const Item* i1, const Item* i2, Item * ret, int riporto) {
	if (ListIsEmpty(i1) && ListIsEmpty(i2)) {
		if (riporto == 0)
			return ret;
		else {
			ElemType a = riporto;
			ret = ListInsertBack(ret, &a);
			ret = SumRec(i1, i2, ret, 0);
		}
	}
	else if (ListIsEmpty(i1) && !ListIsEmpty(i2)) {
		Item * tmp = i2;
		if (tmp->value + riporto == 10) {
			ElemType a = 0;
			ret = ListInsertBack(ret, &a);
			ret = SumRec(i1, ListGetTail(tmp), ret, 1);
		}
		else {
			ElemType a = tmp->value + riporto;
			ret = ListInsertBack(ret, &a);
			ret = SumRec(i1, ListGetTail(tmp), ret, 0);
		}
	}
	else if (!ListIsEmpty(i1) && ListIsEmpty(i2)) {
		Item* tmp = i1;
		if (tmp->value + riporto == 10) {
			ElemType a = 0;
			ret = ListInsertBack(ret, &a);
			ret = SumRec(i2, ListGetTail(tmp), ret, 1);
		}
		else {
			ElemType a = tmp->value + riporto;
			ret = ListInsertBack(ret, &a);
			ret = SumRec(i2, ListGetTail(tmp), ret, 0);
		}
	}
	else {
		Item* tmp1 = i1;
		Item* tmp2 = i2;
		if (tmp1->value + tmp2->value+ riporto >= 10) {
			ElemType a = (tmp1->value + tmp2->value + riporto)%10;
			ret = ListInsertBack(ret, &a);
			SumRec(ListGetTail(tmp1), ListGetTail(tmp2), ret, 1);
		}
		else {
			ElemType a = tmp1->value + tmp2->value + riporto;
			ret = ListInsertBack(ret, &a);
			ret = SumRec(ListGetTail(tmp1), ListGetTail(tmp2), ret, 0);
		}
	}
	return ret;
}


Item* Sum(const Item* i1, const Item* i2) {
	if (ListIsEmpty(i1) && ListIsEmpty(i2))
		return ListCreateEmpty();
	else if (ListIsEmpty(i1) && !ListIsEmpty(i2)) {
		return ListCopy(i2);
	}
	else if (!ListIsEmpty(i1) && ListIsEmpty(i2)) {
		return ListCopy(i1);
	}
	Item* ret = ListCreateEmpty();
	ret = SumRec(i1, i2, ret, 0);
	return ret;
}

Item* ListCreateFromVector(const int* v, size_t v_size) {
	Item* list = ListCreateEmpty();
	for (size_t i = 0; i < v_size; ++i) {
		list = ListInsertBack(list, &v[i]);
	}
	return list;
}

