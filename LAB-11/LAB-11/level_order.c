#include "tree.h"
#include "elemtype.h"
#include <stdio.h>

void LevelOrderRec(Node* t, int level) {
	if (t == NULL)
		return;
	if (level == 1)
		printf("%d", t->value);
	if (level > 1) {
		LevelOrderRec(t->left, level - 1);
		LevelOrderRec(t->right, level - 1);

	}
}


int ContaLivelli(const Node* t) {
	if (t == NULL)
		return 0;
	else {
		if (ContaLivelli(t->right)> ContaLivelli(t->left))
			return ContaLivelli(t->right) + 1;
		else
		{
			return ContaLivelli(t->left) + 1;
		}
	}
}
void LevelOrder(const Node* t) {
	int a = ContaLivelli(t);
	for (int i = 1; i <= a; i++) {
		LevelOrderRec(t, i);
	}
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



int main(void) {
	int v[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	size_t v_size = sizeof(v) / sizeof(int);
	Node* tree = TreeCreateEmpty();

	TreeWriteStdoutPreOrder(tree);
	TreeWriteStdoutInOrder(tree);
	TreeWriteStdoutPostOrder(tree);

	tree = TreeCreateFromVector(v, v_size);

	TreeWriteStdoutPreOrder(tree);
	TreeWriteStdoutInOrder(tree);
	TreeWriteStdoutPostOrder(tree);


	TreeDelete(tree);

	return 1;
}

