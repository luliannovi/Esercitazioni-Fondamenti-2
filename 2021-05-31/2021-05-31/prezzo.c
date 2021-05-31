#include "prezzo.h"
#include <stdio.h>
#include <stdlib.h>


void TrovaArticoliRec(const struct Articolo* a, size_t a_size, int sum, int* now, int i, int sum_now) {
	if (sum_now == sum) {
		for (int k = 0; k < a_size; k++) {
			if (now[k] == 1) {
				printf("%s, ", a[k].nome);
			}
		}
		printf("\n");
		return;
	}
	else if (sum_now > sum)
		return;
	if (i < a_size) {
		now[i] = 1;
		TrovaArticoliRec(a, a_size, sum, now, i + 1, sum_now + a[i].prezzo);
		now[i] = 0;
		TrovaArticoliRec(a, a_size, sum, now, i + 1, sum_now);
	}
}


void TrovaArticoli(const struct Articolo* a, size_t a_size, int sum) {
	if (a == NULL || a_size == 0)
		return;
	int* now = malloc(a_size * sizeof(int));
	TrovaArticoliRec(a, a_size, sum, now, 0, 0);
	free(now);
	return;
}
/*
int main(void) {
	struct Articolo a = { "Monopoli",20 };
	struct Articolo b = { "Carcassone",30 };
	struct Articolo c = { "Perudo",20 };
	struct Articolo* v = malloc(sizeof(struct Articolo) * 3);
	v[0] = a;
	v[1] = b;
	v[2] = c;
	TrovaArticoli(v, 3, 50);


}*/