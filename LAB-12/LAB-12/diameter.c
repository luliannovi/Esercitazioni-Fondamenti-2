#include "elemtype.h"
#include "tree.h"

int Altezza(const Node* t) {
	if (TreeIsEmpty(t))
		return 0;
	if (TreeIsLeaf(t)) {
		return 1;
	}
	int a = Altezza(TreeLeft(t));
	int b = Altezza(TreeRight(t));
	if (a > b)
		return a + 1;
	else
		return b + 1;
}


int DiameterRec(Node* t) {

	if (TreeIsEmpty(t) || TreeIsLeaf(t)) {
		return 0;
	}
	int a = Altezza(TreeLeft(t)) + Altezza(TreeRight(t));
	int b = DiameterRec(TreeRight(t));
	int c = DiameterRec(TreeLeft(t)) ;
	if (a >= c)
		if (a >= b)
			return a + 1;
		else return b ;
	else
		if(c>=b)
			return c ;
}


int Diameter(const Node* t) {
	if (TreeIsEmpty(t))
		return 0;
	int a = DiameterRec(t);
	return a;
}