#include "elemtype.h"
#include "tree.h"

bool Isomorfi(const Node* t1, const Node* t2) {
	if (t1 == NULL && t2 == NULL ) {
		return true;
	}

	if (TreeIsLeaf(t1) && TreeIsLeaf(t2)) {
		return true;
	}
	else if ((TreeIsLeaf(t1) && !TreeIsLeaf(t2))) {
		return false;
	}
	else if ((TreeIsLeaf(t2) && !TreeIsLeaf(t1))) {
		return false;
	}

	if (TreeIsEmpty(TreeRight(t1)) && TreeIsEmpty(TreeRight(t2))) {
		if (ElemCompare(&TreeLeft(t1)->value, &TreeLeft(t2)->value)==0) {
			return Isomorfi(TreeLeft(t1), TreeLeft(t2));
		}
		else
			return false;
	}
	else if (TreeIsEmpty(TreeRight(t1)) && TreeIsEmpty(TreeLeft(t2))) {
		if (ElemCompare(&TreeLeft(t1)->value, &TreeRight(t2)->value)==0) {
			return Isomorfi(TreeLeft(t1), TreeRight(t2));

		}
		else
			return false;
	}
	else if (TreeIsEmpty(TreeLeft(t1)) && TreeIsEmpty(TreeRight(t2))) {
		if (ElemCompare(&TreeRight(t1)->value, &TreeLeft(t2)->value) == 0 ) {
			return Isomorfi(TreeRight(t1), TreeLeft(t2));
		}
		else
			return false;
	}
	else if (TreeIsEmpty(TreeLeft(t1)) && TreeIsEmpty(TreeLeft(t2))) {
		if (ElemCompare(&TreeRight(t1)->value, &TreeRight(t2)->value) == 0) {
			return Isomorfi(TreeRight(t1), TreeRight(t2));
		}
		else
			return false;
	}


	if (ElemCompare(&TreeRight(t1)->value,&TreeRight(t2)->value) ==0 && ElemCompare(&TreeLeft(t1)->value, &TreeLeft(t2)->value) == 0) {
		bool a = Isomorfi(TreeRight(t1), TreeRight(t2));
		bool b = Isomorfi(TreeLeft(t1), TreeLeft(t2));
			
		if (a == true && b == true)
			return true;
		else
			return false;
	}
	else if (ElemCompare(&TreeRight(t1)->value, &TreeLeft(t2)->value) == 0 && ElemCompare(&TreeLeft(t1)->value, &TreeRight(t2)->value) == 0) {
		bool a = Isomorfi(TreeRight(t1), TreeLeft(t2));
		bool b = Isomorfi(TreeLeft(t1), TreeRight(t2));

		if (a == true && b == true)
			return true;
		else
			return false;
	}
	else
		return false;
}