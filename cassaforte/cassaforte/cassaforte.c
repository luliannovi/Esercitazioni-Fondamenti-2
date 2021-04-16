#include <stdio.h>

void CassaforteRec(unsigned int n, unsigned int k,int i, int* vet, int* cont) {
	if (i == n) {
		int sum = 0;
		for (int p = 0; p < n; p++) {
			sum += vet[p];
		}
		if (sum == k) {
			(*cont)++;
			printf("%d) { ", *cont);
			for (int u = 0; u < n; u++) {
				printf("%d ", vet[u]);
			}
			printf("}\n");
			return;
		}
		else
			return;
	}

	for (int y = 0; y < 10; y++) {
		vet[i] = y;
		CassaforteRec(n, k, i+1, vet, cont);
	}
}

int Cassaforte(unsigned int n, unsigned int k) {
	int* vet = malloc(n * sizeof(int));
	int cont = 0;
	CassaforteRec(n, k, 0, vet,&cont);
	free(vet);
	return 0;
}

int main(void) {
	Cassaforte(5, 10);
	return 0;
}