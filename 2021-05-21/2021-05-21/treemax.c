#include "elemtype.h"
#include "tree.h"
#include <limits.h>
const ElemType* BstTreeMax(const Node* n) {
	if (TreeIsEmpty(n))
		return NULL;
	Node* tmp = n;
	while (TreeRight(tmp) != NULL) {
		tmp = TreeRight(tmp);
	}
	return TreeGetRootValue(tmp);

}

ElemType * TreeMaxRec(Node* n, ElemType* max) {
	if (TreeIsEmpty(n))
		return max;
	if (ElemCompare(&n->value, max) > 0)
		max = &n->value;
	max = TreeMaxRec(TreeLeft(n), max);
	max = TreeMaxRec(TreeRight(n), max);
	return max;
}

const ElemType* TreeMax(const Node* n) {
	if (TreeIsEmpty(n))
		return NULL;
	Node* tmp = n;
	ElemType* max = &tmp->value;
	max = TreeMaxRec(TreeLeft(tmp),max);
	max = TreeMaxRec(TreeRight(tmp),max);
	return max;
}
/*
int main(void) {
	ElemType v;
	Node *a;
	Node *l;
	v = 6;
	l = TreeCreateRoot(&v, NULL, NULL);
	Node* r;
	v = 8;
	r = TreeCreateRoot(&v, NULL, NULL);
	v = 4;
	a = TreeCreateRoot(&v, l, r);
	TreeMax(a);
	return 0;
}*/