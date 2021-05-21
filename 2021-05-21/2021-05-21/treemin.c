#include "elemtype.h"
#include "tree.h"

const ElemType* BstTreeMin(const Node* n) {
	if (TreeIsEmpty(n))
		return NULL;
	Node* tmp = n;
	while (TreeLeft(tmp) != NULL) {
		tmp = TreeLeft(tmp);
	}
	return TreeGetRootValue(tmp);
}

ElemType* TreeMinRec(Node* n, ElemType* min) {
	if (TreeIsEmpty(n))
		return min;
	if (ElemCompare(&n->value, min) <= 0)
		min = &n->value;
	min = TreeMinRec(TreeLeft(n), min);
	min = TreeMinRec(TreeRight(n), min);
	return min;
}


const ElemType* TreeMin(const Node* n) {
	if (TreeIsEmpty(n))
		return NULL;
	Node* tmp = n;
	ElemType* min = &tmp->value;
	min = TreeMinRec(TreeLeft(tmp), min);
	min = TreeMinRec(TreeRight(tmp), min);
	return min;


}