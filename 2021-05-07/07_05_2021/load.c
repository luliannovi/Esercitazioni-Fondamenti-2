#include "elemtype.h"
#include "list.h"
#include <stdlib.h>
#include <stdio.h>

Item* ListLoad(const char* filename) {
	if (filename == NULL)
		return NULL;

	FILE * f = fopen(filename, "r");
	if (f == NULL)
		return NULL;
	Item * list = ListCreateEmpty();
	ElemType * letto = malloc(sizeof(ElemType));
	while (!feof(f)) {
		int i = fscanf(f, "%d", letto);
		if (i != 1) {
			free(letto);
			return list;
		}
		list = ListInsertHead(letto, list);
	}

	fclose(f);
	free(letto);
	return list;
}
/*
int main(void) {
	LoadList("data_00.txt");
	return 0;
}*/