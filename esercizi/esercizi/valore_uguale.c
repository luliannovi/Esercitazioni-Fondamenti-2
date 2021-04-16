#include <stdlib.h>
#include <stdio.h>

void SubValue(int n, int k, int* cont, int* vet, int i,int sum,int h) {
	if (sum==k) {
		*cont += 1;
		printf("%d--> {",*cont);
		for (int y = 0; y < i; y++)
			printf(" %d", vet[y]);
		printf("}\n");
	}
	if (i == n)
		return;
	if (sum > k)
		return;
	for (int p = h; p <= n; p++) {
		vet[i] = p;
		SubValue(n, k, cont, vet, i + 1, sum + vet[i],p+1);
		vet[i] = 0;
	}
}

int Value(int n, int k) {
	int* vet = calloc(n, sizeof(int));
	int cont = 0;
	SubValue(n, k, &cont, vet, 0,0,1);
	return 0;
}

void SubCombinazione(int n, int k, int* vet, int* cont, int i, int sum) {
	if (i == n) {
		if (sum == k) {
			*cont += 1;
			printf("%d --> ", *cont);
			for (int p = 0; p < n; p++) {
				printf(" %d", vet[p]);
			}
			printf("\n");
		}
		else
			return;
	}
	if (sum > k)
		return;

	for (int p = 0; p < 10 && i<n; p++) {
		vet[i] = p;
		SubCombinazione(n, k, vet, cont, i + 1, sum + vet[i]);
	}
}


int Combinazione(int n, int k) {
	int* vet = calloc(n, sizeof(int));
	int cont = 0;
	SubCombinazione(n, k, vet, &cont, 0, 0);
	return 0;
}
int main() {
	Value(5, 7);
	Combinazione(3, 6);
	return 0;
}