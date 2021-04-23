#include "sciatori.h"
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
Sciatore* Accoppia(double* altezze, double* lunghezze, size_t v_size) {
	if (v_size == 0)
		return NULL;
	Sciatore* ris = malloc(v_size * sizeof(Sciatore));
	double diff = INT_MAX;
	int A = 0;
	int L = 0;
	int p = 0;
	bool* fatto_a = calloc(v_size, sizeof(bool));
	bool* fatto_l = calloc(v_size, sizeof(bool));
	while (p < v_size) {
		for (int a = 0; a < v_size; a++) {
			for (int l = 0; l < v_size; l++) {
				if ((abs(altezze[a] - lunghezze[l]) < diff)&& (fatto_a[a]!=true) && (fatto_l[l]!=true)) {
					L = l;
					A = a;
					diff = abs(altezze[a] - lunghezze[l]);
				}
			}
		}
		
		ris[p].a = altezze[A];
		ris[p].l = lunghezze[L];
		fatto_a[A] = true;
		fatto_l[L] = true;
		diff = INT_MAX;
		p += 1;
	}

	free(fatto_a);
	free(fatto_l);
	return ris;
}