#include <stdlib.h>
#include "tree.h"

bool TreeIsMirrorRec(const Node* l, const Node* r) {


	if ((TreeIsEmpty(l) && !TreeIsEmpty(r)) || (TreeIsEmpty(r)&&!TreeIsEmpty(l))) {
		return false;
	}

	if (TreeIsEmpty(l) && TreeIsEmpty(r)) {
		return true;
	}

	if ((*TreeGetRootValue(l) == *TreeGetRootValue(r)) && TreeIsLeaf(l) && TreeIsLeaf(r)) {
		return true;
	}

	
	if (*TreeGetRootValue(l) == *TreeGetRootValue(r)) {
		return TreeIsMirrorRec(TreeLeft(l), TreeRight(r)) && TreeIsMirrorRec(TreeRight(l), TreeLeft(r));
	}

	return false;
}

bool TreeIsMirror(const Node* t) {
	
	if (TreeIsEmpty(t) || TreeIsLeaf(t)) {
		return true;
	}


	Node* l = TreeLeft(t);
	Node* r = TreeRight(t);
	
	return TreeIsMirrorRec(l,r);

}