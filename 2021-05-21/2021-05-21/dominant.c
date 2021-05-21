#include "elemtype.h"
#include "tree.h"

int CountDominant(const Node* t) {
	if (TreeIsEmpty(t))
		return 0;
	int tot = 0;
	if (TreeLeft(t) == NULL && TreeRight(t) == NULL)
		return 0;
	if (TreeLeft(t) == NULL && TreeRight(t) != NULL) {
		if (ElemCompare(&t->value, &TreeRight(t)->value) > 0)
			tot++;
	}
	else if (TreeLeft(t) != NULL && TreeRight(t) == NULL) {
		if (ElemCompare(&t->value,&TreeLeft(t)->value)>0)
			tot++;
	}
	else {
		ElemType a = TreeLeft(t)->value + TreeRight(t)->value;
		if (ElemCompare(&t->value,&a)>0)
			tot++;
	}
	tot += CountDominant(TreeLeft(t));
	tot += CountDominant(TreeRight(t));
	return tot;
}
