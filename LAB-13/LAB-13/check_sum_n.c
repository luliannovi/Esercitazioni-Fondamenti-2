#include "tree.h"
#include "elemtype.h"
#include <stdbool.h>


ElemType *  VisitaDiscendenti(const Node* t, int* tot, ElemType* a) {
	if (!TreeIsEmpty(t)) {
		a = realloc(a, (*tot + 1) * sizeof(ElemType));
		a[*tot] = t->value;
		
		(*tot) = *tot +1;
		a = VisitaDiscendenti(TreeLeft(t), tot, a);
		a = VisitaDiscendenti(TreeRight(t), tot, a);
	}
	return a;
}

bool CheckSumN_help(ElemType* vet, int n, int tot, int pos) {
	if (vet == NULL)
		return false;
	for (int i = 0; i < tot; i++) {
		if (i == pos)
			continue;
		else {
			if (vet[pos] + vet[i] == n)
				return true;
		}
	}
	return false;
}

bool CheckSumN(const Node* t, int n) {
	if (t == NULL || TreeIsEmpty(TreeLeft(t)) || TreeIsEmpty(TreeRight(t)))
		return false;
	ElemType* a = malloc(sizeof(ElemType));
	int tot = 0;
	a = VisitaDiscendenti(t, &tot, a);
	bool ok = false;
	for (int i = 0; i < tot && ok !=true; i++) {
		ok = CheckSumN_help(a, n, tot, i);
	}
	free(a);
	return ok;
}

Node* TreeCreateFromVectorRec(const int* v, size_t v_size, int i) {
	if (i >= (int)v_size) {
		return NULL;
	}

	Node* l = TreeCreateFromVectorRec(v, v_size, i * 2 + 1);
	Node* r = TreeCreateFromVectorRec(v, v_size, i * 2 + 2);

	return TreeCreateRoot(&v[i], l, r);
}

Node* TreeCreateFromVector(const int* v, size_t v_size) {
	return TreeCreateFromVectorRec(v, v_size, 0);
}

/*
int main(void) {
	int v[3] = { 3,2,4 };
	Node* a = TreeCreateFromVector(v, 3);
	CheckSumN(a, 1);


}
*/