#include "elemtype.h"
#include "tree.h"

Node* Get(Node* n) {
	return n;
}

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

Node* Successivo(Node* n, Node ** padre) {
	if (TreeIsEmpty(n))
		return NULL;
	Node* tmp = n->left;
	*padre = Get(n);
	while (tmp->left != NULL) {
		*padre = Get(tmp);
		tmp = tmp->left;
	}
	return tmp;
}

Node* DeleteBstNodeRec(Node* n, const ElemType* key, Node * father) {
	if (TreeIsEmpty(n))
		return n;
	if (ElemCompare(key, &n->value) == 0) {
		if (TreeIsEmpty(father)) {
			Node** p = malloc(sizeof(Node*));
			Node* succ = Successivo(n,p);
			if (succ == NULL) {
				free(p);
				return n->right;
			}
			if (TreeIsEmpty(TreeRight(succ))) {
				succ->right = n->right;
				succ->left = n->left;
				p[0]->left = NULL;
				free(p);
				return succ;
			}
			else {
				succ->right = n->right;
				succ->left = n->left;
				p[0]->left = succ->right;
				free(p);
				return succ;
			}
		}
		else {
			Node** p = malloc(sizeof(Node*));
			Node* succ = Successivo(n, p);
			if (succ == NULL) {
				free(p);
				return n->right;
			}
			if (TreeIsEmpty(TreeRight(succ))) {
				succ->right = n->right;
				succ->left = n->left;
				p[0]->left = NULL;
				free(p);
				return succ;
			}
			else {
				succ->right = n->right;
				succ->left = n->left;
				p[0]->left = succ->right;
				free(p);
				return succ;
			}
		}
	}else if(ElemCompare(key,&n->value)<0)
		n->left = DeleteBstNodeRec(n->left, key, n);
	else
		n->right = DeleteBstNodeRec(n->right, key, n);
	return n;
}

bool Presente(Node* n, const ElemType* key) {
	if (n == NULL)
		return false;
	if (ElemCompare(key, &n->value) == 0)
		return true;
	bool a = Presente(n->left, key);
	if (a == true)
		return true;
	else {
		a = Presente(n->right, key);
		return a;
	}
}

Node* DeleteBstNode(Node* n, const ElemType* key) {
	if (TreeIsEmpty(n))
		return n;
	bool presente = Presente(n,key);


	if (presente == false)
		return n;
	Node* tmp = DeleteBstNodeRec(n, key, NULL);
	return tmp;
}

Node* TreeCreateFromVectorRec(const int* v, size_t v_size, int i) {
	if (i >= (int)v_size) {
		return NULL;
	}

	Node* l = TreeCreateFromVectorRec(v, v_size, i * 2 + 1);
	Node* r = TreeCreateFromVectorRec(v, v_size, i * 2 + 2);

	return TreeCreateRoot(&v[i], l, r);
}

Node* TreeCreateFromVector(const int* v, size_t v_size) {
	return TreeCreateFromVectorRec(v, v_size, 0);
}
/*
int main(void) {
	int v[] = {5,4,7,2,3,6,8 };
	size_t v_size = sizeof(v) / sizeof(int);
	Node* tree = TreeCreateEmpty();
	tree = TreeCreateFromVector(v, 7);
	ElemType a = 7;
	Node *b = DeleteBstNode(tree, &a);
}*/