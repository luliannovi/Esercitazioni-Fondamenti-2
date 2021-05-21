#include "elemtype.h"
#include "tree.h"

void VisitaDiscendenti(Node* n, const ElemType* key, Node* ok, Node* father) {
	if (TreeIsLeaf(n))
		return;

	if (TreeRight(n)!=NULL && ElemCompare(TreeGetRootValue(TreeRight(n)), key) == 0){
		ok = TreeRight(n);
		father = n->right;
	}
	if (TreeLeft(n) !=NULL && ElemCompare(TreeGetRootValue(TreeLeft(n)), key) == 0) {
		ok = TreeLeft(n);
		father = n->left;
	}
	VisitaDiscendenti(TreeRight(n), key, ok, father);
	VisitaDiscendenti(TreeLeft(n), key, ok, father);
}

Node* SuccessivoEliminaPadre(Node* n) {
	if (TreeIsEmpty(n))
		return NULL;
	Node *tmp = n->left;
	Node* father = tmp;
	while (tmp->left!=NULL) {
		father = tmp;
		tmp = tmp->left;
	}
	father->left = NULL;
	return tmp;
}

Node* Successivo(Node* n) {
	if (TreeIsEmpty(n))
		return NULL;
	Node* tmp = n->left;
	while (tmp->left != NULL) {
		tmp = tmp->left;
	}
	return tmp;
}

Node* DeleteBstNode(Node* n, const ElemType* key) {
	if (TreeIsEmpty(n) || key==NULL)
		return NULL;
	Node* ok = NULL;
	Node* total = n;
	Node* father = NULL;
	ElemType *k = key;
	if (!TreeIsEmpty(n)) {
		if (ElemCompare(&(n->value), k) == 0)
			ok = n;
		VisitaDiscendenti(n, k, ok,father);
	}
	if (TreeIsLeaf(ok)) {
		father = NULL;
		TreeDelete(ok);
	}
	else if (ok->left == NULL && ok->right != NULL) {
		father = ok->right;
		TreeDelete(ok);
	}
	else if (ok->left != NULL && ok->right == NULL) {
		father = ok->left;
		TreeDelete(ok);
	}
	else {
		Successivo(ok)->left = ok->left;
		Successivo(ok)->right = ok->right;
		father = Successivo(ok);
	
		TreeDelete(SuccessivoEliminaPadre(ok));
	}
	
	return total;
}


