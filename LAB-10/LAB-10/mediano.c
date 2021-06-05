#include "elemtype.h"
#include "tree.h"
#include <float.h>

int ContaNodi(Node* t,int * tot) {
	*tot += 1;
	if (!TreeIsEmpty(TreeLeft(t))) {
		ContaNodi(TreeLeft(t),tot);
	}
	if (!TreeIsEmpty(TreeRight(t))) {
		ContaNodi(TreeRight(t), tot);
	}
}
void TrovaNodo(Node* t, int n,int *i,ElemType *a) {
	if (TreeLeft(t) != NULL) 
		TrovaNodo(TreeLeft(t), n, i,a);
	
	
	if (*i == n) {
		*a = t->value;
		return;
	}
	*i += 1;
	if (TreeRight(t) != NULL)
		TrovaNodo(TreeRight(t), n, i, a);
	
}

double Mediano(const Node* t) {
	if (TreeIsEmpty(t))
		return DBL_MAX;
	int tot = 0;
	ContaNodi(t, &tot);
	if (tot % 2 == 0) {
		ElemType ac;
		ElemType bc;
		int a = 1;
		int b = 1;
		TrovaNodo(t, tot / 2, &a, &ac);
		TrovaNodo(t, (tot / 2) +1, &b, &bc);
		return (double)(ac + bc) / 2;
	}
	else {
		ElemType ac;
		int a = 1;
		TrovaNodo(t, (tot / 2)+1, &a, &ac);
		return (double)ac;
	}
}
/*
int main(void) {
	Node a;
	Node b;
	Node c;
	Node d;
	Node e;
	Node f;
	Node g;
	a.value = 1;
	b.value = 2;
	c.value = 3;
	d.value = 4;
	e.value = 5;
	f.value = 6;
	g.value = 7;
	d.left = &b;
	d.right = &f;
	b.left = &a;
	b.right = NULL;
	a.left = NULL;
	a.right = NULL;
	c.left = NULL;
	c.right = NULL;
	f.right = &g;
	f.left = &e;
	e.left = e.right = g.right = g.left = NULL;
	Mediano(&d);
	return 0;


}*/