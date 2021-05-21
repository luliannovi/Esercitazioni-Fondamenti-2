#include "elemtype.h"
#include "tree.h"
#include <math.h>
int GetHigh(const Node* t) {
	int tot = -1;
	Node* tmp = t;
	while (!TreeIsEmpty(tmp)){
		tmp = tmp->left;
		tot++;
	}
	return tot;
}

void RiempiVettoreRec(Node* t, int now, int livello, ElemType* vector, int* current) {
	if (now == livello) {
		vector[*current] = t->left->value;
		(*current)++;
		vector[*current] = t->right->value;
		(*current)++;
		return;
	}
	RiempiVettoreRec(t->left, now + 1, livello, vector, current);
	RiempiVettoreRec(t->right, now + 1, livello, vector, current);
	return;
}

void RiempiVettore(Node* t, int livello, ElemType* vector, int * current) {
	RiempiVettoreRec(t, 0, livello, vector, current);
	return;
}



bool Specchio(ElemType* vector, int size) {
	int i = 0;
	while ((ElemCompare(&vector[i], &vector[size - 1 - i]) == 0) && i<size/2) {
		i++;
	}
	if (i == size / 2)
		return true;
	else
		return false;
}

int ControlloParitaNodi(Node* t,int * tot) {
	if (TreeIsEmpty(t))
		return 0;
	Node * tmp = t;
	if (TreeIsLeaf(tmp))
		*tot = *tot + 1;
	else if(tmp->right !=NULL && tmp->left == NULL){
		ControlloParitaNodi(t->right, tot);
		*tot = *tot + 1;
	}
	else if (tmp->right == NULL && tmp->left != NULL) {
		ControlloParitaNodi(t->left, tot);
		*tot = *tot + 1;
	}
	else {
		ControlloParitaNodi(t->right, tot);
		ControlloParitaNodi(t->left, tot);
		*tot = *tot + 1;
	}
	
	return  *tot;
}


bool TreeIsMirror(const Node* t) {
	if (TreeIsEmpty(t))
		return true;
	int levels = GetHigh(t);
	int noditot = pow(2, levels+1)-1;
	int a = 0;
	int b = 0;
	if (ControlloParitaNodi(t->left,&a) != ControlloParitaNodi(t->right,&b))
		return false;
	ElemType *vector = malloc(noditot * sizeof(ElemType));
	int current = 0;
	for (int i = 0; i < levels; i++) {
		RiempiVettore(t, i , vector,&current);
	}
	for (int i = 0; i < levels; i++) {
		if (Specchio(&vector[i * levels], pow(2, i + 1)) == false) {
			free(vector);
			return false;
		}
	}
	free(vector);
	return true;
}
/*
int main(void) {
	ElemType v;
	Node* a;
	Node* l;
	v = 6;
	
	Node* r;
	v = 8;
	r = TreeCreateRoot(&v, NULL, NULL);
	v = 4;
	
	Node* c;
	v = 6;
	c = TreeCreateRoot(&v, NULL, NULL);
	l = TreeCreateRoot(&v, c, NULL);
	a = TreeCreateRoot(&v, l, r);
	TreeIsMirror(a);
	return 0;
}*/