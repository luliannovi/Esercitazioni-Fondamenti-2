#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>

void StazioniServizioRec(double m, const double* d, const double* p, size_t n, int *percorsi, int * vcurr, int i, float *serbatoio, float * prezzi,int *best, float*pricebest,int * tot) {
	
	if (*percorsi + (*serbatoio / 0.05) >=m) {
		float prezzo = 0;
		for (int k = 0; k < i; k++) {

			prezzo += prezzi[k];
		}
		if (prezzo < *pricebest) {
			*tot = i;
			*pricebest = prezzo;
			for (int k = 0; k < i; k++) {
				best[k] = vcurr[k];
			}
		}
		return;
	}

	if (i >= n)
		return;
	*serbatoio -= 0.05 * d[i];
	
	if (*serbatoio < 0) {
		*serbatoio += 0.05 * d[i];
		return;
	}
	
	*percorsi += d[i];

	int a = *percorsi;
	float b = *serbatoio;
	vcurr[i] = 0;
	prezzi[i] = 0;
	StazioniServizioRec(m, d, p, n, percorsi, vcurr, i + 1,serbatoio,prezzi,best,pricebest,tot);
	

	*serbatoio = b;
	*percorsi = a;
	vcurr[i] = 1;
	prezzi[i] = p[i] * (30 - *serbatoio);
	*serbatoio = 30;
	StazioniServizioRec(m, d, p, n, percorsi, vcurr, i + 1, serbatoio, prezzi,best,pricebest,tot);
	
}




void StazioniServizio(double m, const double* d, const double* p, size_t n) {
	float serbatoio = 30;
	float pricebest = INT_MAX;
	int percorsi = 0;
	int* vcurr = calloc(n, sizeof(int));
	int* best = calloc(n, sizeof(int));
	float* prezzi = calloc(n, sizeof(float));
	int tot = -1;
	StazioniServizioRec(m, d, p, n, &percorsi, vcurr, 0, &serbatoio, prezzi, best, &pricebest,&tot);
	if (tot == -1) {
		printf("Non esistono soluzioni");
		free(vcurr);
		free(best);
		free(prezzi);
		return;
	}
	for (int i = 0; i < tot; i++) {
		if (best[i] == 1) {
			printf("%d ", i);
		}
		
	}
	printf("\n");
	printf("Spesa totale: %f euro", pricebest);
	free(vcurr);
	free(best);
	free(prezzi);
	return;
}
/*
int main(void) {
	double m = 2020;
	double d[] = { 260.0000, 284.0000 ,308.0000 ,332.0000 ,356.0000 };
	double p[] = { 35.0000 , 35.0000 ,33.0000 ,29,23 };
	StazioniServizio(m, d, p, 5);
	return 0;

}*/