#include "tree.h"
#include "elemtype.h"
#include <stdbool.h>
#include <stdlib.h>

bool TreeIsMirrorRec(const Node* l, const Node * r) {
	if (!TreeIsEmpty(r) && TreeIsEmpty(l))
		return false;
	else if (TreeIsEmpty(r) && !TreeIsEmpty(l))
		return false;
	else if (TreeIsEmpty(r) && TreeIsEmpty(l))
		return true;
	else if (ElemCompare(&r->value, &l->value) == 0 && TreeIsLeaf(r) && TreeIsLeaf(l))
			return true;
	else if(ElemCompare(&r->value, &l->value) == 0)
		return TreeIsMirrorRec(TreeLeft(r), TreeRight(l)) && TreeIsMirrorRec(TreeRight(r), TreeLeft(l));
	
	return false;
}


bool TreeIsMirror(Node* t) {
	if (TreeIsEmpty(t) || TreeIsLeaf(t))
		return true;
	return TreeIsMirrorRec(TreeLeft(t), TreeRight(t));	
}