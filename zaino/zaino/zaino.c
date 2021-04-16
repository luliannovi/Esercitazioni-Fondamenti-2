#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void ZainoRec(int P, int* oggetti,int * valori, int n, int* pesi, int i, int* max, int * ok) {
	if (i == n) {
		int sum = 0;
		for (int j = 0; j < n; j++) {
			sum += pesi[j] * oggetti[j];
		}
		int a = 0;
		for (int j = 0; j < n; j++) {
			a += oggetti[j] * valori[j];
		}

		if (a<*max || sum >P)
			return;
		else if (a> *max && sum <= P) {
			*max = sum;
			
			for (int j = 0; j < n; j++) {
				ok[j] = oggetti[j];
			}
			return;
		}
	}

	oggetti[i] = 1;
	ZainoRec(P, oggetti,valori, n, pesi, i+1, max,ok);
	oggetti[i] = 0;
	ZainoRec(P, oggetti,valori, n, pesi, i+1, max, ok);
}

void Zaino(int P, int* oggetti,int * valori, int n, int* pesi) {
	int max = 0;
	int* ok = calloc(n, sizeof(int));
	ZainoRec(P, oggetti,valori, n, pesi, 0, &max,ok);
	for (int j = 0; j < n; j++) {
		printf("%d", ok[j]);
	}
	return;
}

int main() {
	int oggetti[] = { 0,0,0,0 };
	int valori[] = { 3,5,6,10 };
	int pesi[] = { 2,3,4,5 };
	Zaino(8, oggetti, valori, 4, pesi);
	return 0;
}