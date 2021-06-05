#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool Presente(int* vet, int n, int len) {
	for (int i = 0; i < len; i++) {
		if (vet[i] == n)
			return true;

	}
	return false;
}

void RegoleRec(const char* r, int len, int i, int*vet) {
	if (i == len + 1) {
		for (int k = 0; k < len + 1; k++)
			printf("%d ", vet[k]);
		printf("\n");
		return;
	}
	if (i == 0) {
		if (r[0] == 'D' || r[0] == 'd') {
			for (int y = 2; y <= len + 1; y++) {
				vet[i] = y;
				RegoleRec(r, len, i + 1, vet);
			}
		}
		else if (r[0] == 'I' || r[0] == 'i') {
			for (int y = 1; y <= len + 1; y++) {
				vet[i] = y;
				RegoleRec(r, len, i + 1, vet);
			}
		}
	}
	else {
		if (r[i - 1] == 'D' || r[i-1] == 'd') {
			for (int y = vet[i - 1] -1; y >0; y--) {
				if (!Presente(vet, y, i)) {
					vet[i] = y;
					RegoleRec(r, len, i + 1, vet);
				}
			}
		}else if (r[i-1] == 'I' || r[i-1] == 'i') {
			for (int y = vet[i - 1] +1; y <=len+1; y++) {
				if (!Presente(vet, y, i)) {
					vet[i] = y;
					RegoleRec(r, len, i + 1, vet);
				}
			}
		}
		
	}
}


void Regole(const char* r) {
	size_t len = strlen(r);
	if (len == 0) {
		printf("1");
		return;
	}
	int* vet = malloc((len +1)* sizeof(int));
	RegoleRec(r, len, 0,vet);
	free(vet);
	return;

}



