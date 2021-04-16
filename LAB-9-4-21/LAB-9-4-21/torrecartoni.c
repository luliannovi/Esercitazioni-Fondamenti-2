#include "torrecartoni.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>

void VerificaBest(const Cartone* c, int* vcurr, int* best,int * tot_best, int k) {
	int h1 = 0;
	int h2 = 0;
	for (int i = 0; i < k; i++) {
		h1 += c[vcurr[i]].a;
	}
	for (int i = 0; i < *tot_best; i++) {
		h2 += c[vcurr[i]].a;
	}

	if (h1 > h2) {
		for (int i = 0; i < k; i++) {
			best[i] = vcurr[i];
			*tot_best = k;
		}
	}
}


void TorreCartoniRec(const Cartone* c, size_t n, int i, int * tot_best, int*best,int*vcurr, int limite) {
	for (int j = 0; j < n; j++) {
		int ok = 1;
		for (int k = 0; k < i; k++) {
			if (j == vcurr[k]) { //ho già posizionato questo cartone?
				ok = 0;
				break;
			}
		}
		if (c[j].p<limite && ok==1) {
			vcurr[i] = j;
			VerificaBest(c, vcurr, best, tot_best, i+1); //verifico sia la miglior disposizione, nel caso aggiorno il mio best
			TorreCartoniRec(c, n, i + 1, tot_best, best, vcurr, c[j].l);
		}
	}

	if (i == n-1)
		return;
}


void TorreCartoni(const Cartone* c, size_t n) {
	int *best = calloc(n, sizeof(int));
	int *vcurr = calloc(n, sizeof(int));
	int tot_cartoni = 0;
	TorreCartoniRec(c, n, 0, &tot_cartoni,best,vcurr,INT_MAX);
	for (int i =tot_cartoni-1; i >=0; i--) {
		printf("%d\n", best[i]);
	}
	int p = 0;
	for (int i = tot_cartoni - 1; i >= 0; i--) {
		p+= c[best[i]].a;
	}
	printf("altezza : %d cm", p);
	free(best);
	free(vcurr);
	return;
}
/*
int main(void) {
	Cartone* c = malloc(6 * sizeof(Cartone));
	c[0].a = 20;
	c[0].p = 25;
	c[0].l = 50;
	c[1].a = 10;
	c[1].p = 10;
	c[1].l = 8;
	c[2].a = 3;
	c[2].p = 9;
	c[2].l = 5;
	c[3].a = 20;
	c[3].p = 5;
	c[3].l = 200;
	c[4].a = 10;
	c[4].p = 10;
	c[4].l = 202;
	c[5].a = 3;
	c[5].p = 24;
	c[5].l = 55;
	TorreCartoni(c, 6);
	free(c);
	return 0;
}*/