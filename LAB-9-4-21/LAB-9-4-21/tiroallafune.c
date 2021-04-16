#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

bool Verifica(int j, int* argv[], int* a) {
	for (int k = 0; k <= j ; k++) {
		if (a[k] == argv[j])
			return false;
	}
	return true;
}



void TiroFuneRec(int n, int* a, int* b,int* argv, int i,int *best_diff,int *bestA, int* bestB) {
	if (i == n / 2) {
		
		int SA = 0;
		int SB = 0;
		for (int k = 0; k < n / 2; k++) {
			SA += a[k];
		}
		for (int k = 0; k < (n - n / 2); k++) {
			SB += b[k];
		}
		if (abs(SA - SB) < *best_diff) {
			*best_diff = abs(SA - SB);
			for (int k = 0; k < n / 2; k++) {
				bestA[k] = a[k];
			}
			for (int k = 0; k < (n - n / 2); k++) {
				bestB[k] = b[k];
			}
		}
		return;
	}

	for (int j = 0; j < n ; j++) {
		if (Verifica(j, argv, a)) {
			a[i] = argv[j];
			for (int k = 0; k < (n - n / 2); k++) {
				for (int j = 0; j < n; j++) {
					if (Verifica(j, argv, a) && Verifica(j, argv, b)) {
						b[k] = argv[j];
						break;
					}
				}
			}
			TiroFuneRec(n, a, b, argv, i + 1,best_diff,bestA,bestB);
		}
	}
}


void TiroFune(int n, int* a, int* b, int *argv) {
	int best_diff = INT_MAX;
	int* bestA = malloc((n / 2) * sizeof(int));
	int* bestB = malloc((n - n / 2) * sizeof(int));
	TiroFuneRec(n, a, b, argv, 0,&best_diff,bestA,bestB);
	printf("{");
	for (int k = 0; k < n / 2; k++) {
		printf("%d ,", bestA[k]);
	}
	printf("} ,");
	printf("{");
	for (int k = 0; k < (n-n / 2); k++) {
		printf("%d ,", bestB[k]);
	}
	printf("}");
	free(bestA);
	free(bestB);
	return;
}


/*
int main(int argc, void* argv[]) {
	int* vero = malloc((argc - 1) * sizeof(int));
	for (int i = 0; i < argc-1; i++) {
		vero[i] = atoi(argv[i + 1]);
	}
	int* a = malloc(((argc-1)/2) * sizeof(int));
	int* b = malloc(((argc-1) - ((argc-1) / 2)) * sizeof(int));
	TiroFune(argc-1, a, b, vero);
	free(a);
	free(b);
	return 0;
}*/