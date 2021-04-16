#include <stdio.h>
#include <stdbool.h>
void SubSetRec(unsigned int n, unsigned int i, int* vet, int* cont) { //solo per numeri pari
	if (i == n) {
		bool ok = false;
		for (int o = 0; o < n; o++) {
			if (vet[o] % 2 == 0)
				ok = true;
		}
		if (ok == true) {
			(*cont)++;
			printf("%d) {", *cont);
			for (int o = 0; o < n; o++) {
				printf("%d ", vet[o]);
			}
			printf("}\n");
		}
		return;
	}

	for (int y = 1; y <= n; y++) {
		vet[i] = y;
		SubSetRec(n, i + 1, vet, cont);
	}
}

int SubSet(unsigned int n) {
	int* vet = malloc(n * sizeof(int));
	int cont = 0;
	SubSetRec(n, 0, vet, &cont);
	free(vet);
	return 0;
}

int main(void) {
	SubSet(3);
	return 0;
}