#include "tree.h"
#include "elemtype.h"
#include <stdbool.h>

bool Equivalenti(const Node* t1, const Node* t2) {
	if (TreeIsEmpty(t1) && TreeIsEmpty(t2))
		return true;
	if (TreeIsLeaf(t1) && TreeIsLeaf(t2)) {
		if (ElemCompare(&t1->value, &t2->value) >= 0) {
			if (t1->value % t2->value == 0)
				return true;
			else
				return false;
		}
		else
			if (t2->value % t1->value == 0)
				return true;
			else
				return false;
	}
	if ((!TreeIsLeaf(t1) && TreeIsLeaf(t2)) || (TreeIsLeaf(t1) && !TreeIsLeaf(t2)))
		return false;
	if (TreeIsEmpty(t1) && !TreeIsEmpty(t2))
		return false;
	else if (!TreeIsEmpty(t1) && TreeIsEmpty(t2))
		return false;
	else if (ElemCompare(&t1->value, &t2->value) != 0)
		return false;
	else {
		return Equivalenti(TreeRight(t1), TreeRight(t2)) && Equivalenti(TreeLeft(t1), TreeLeft(t2));
	}
}