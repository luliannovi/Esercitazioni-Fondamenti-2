#include "elemtype.h"
#include "tree.h"
#include <stdlib.h>
#include <stdio.h>


Node* BstInsert(const ElemType* e, Node* n) {
	if (TreeIsEmpty(n))
		return TreeCreateRoot(e, NULL, NULL);
	Node* tmp = n;
	while (1) {
		if (ElemCompare(e, &tmp->value) <= 0) {
			if (TreeLeft(tmp) != NULL)
				tmp = TreeLeft(tmp);
			else {
				tmp->left = TreeCreateRoot(e, NULL, NULL);
				tmp = TreeLeft(tmp);
				break;
			}
		}
		else {
			if (TreeRight(tmp) != NULL)
				tmp = TreeRight(tmp);
			else {
				tmp->right = TreeCreateRoot(e, NULL, NULL);
				tmp = TreeRight(tmp);
				break;
			}
		}
	}
	return n;
}


Node* BstInsertRec(const ElemType* e, Node* n) {
	if (TreeIsEmpty(n))
		return TreeCreateRoot(e, NULL, NULL);
	if (ElemCompare(e, &n->value) <= 0) {
		n->left = BstInsertRec(e, TreeLeft(n));
	}
	else
		n->right = BstInsertRec(e, TreeRight(n));

	return n;
}