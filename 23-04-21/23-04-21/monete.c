#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


int* Monete(int* tagli, size_t tagli_size, int budget) {
	if (budget <= 0) {
		return NULL;
	}
	int *rt = calloc(tagli_size, sizeof(int));

	for (int i = 0; i < tagli_size && budget >0; i++) {
		rt[i] = budget / tagli[i];
		budget = budget % tagli[i];
	}
	return rt;
}