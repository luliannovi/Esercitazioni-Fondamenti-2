#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
void CassaforteRec(int n, int k, int i, int* comb, int *sum,int *tot) {
	//if (*sum > k)
		//return;
	if (i == n) {
		if (*sum == k) {
			*tot += 1;
			printf("%d-esima Combinazione: ",*tot);
			for (int j = 0; j < n; j++) {
				printf("%d ", comb[j]);
			}
			printf("\n");
		}
		return;
	}

	for (int j = 0; j < 10; j++) {
		comb[i] = j;
		*sum += j;
		CassaforteRec(n, k, i + 1, comb, sum,tot);
		*sum -= j;
	}
}

void Cassaforte(int n, int k) {
	int* comb = calloc(n, sizeof(int));
	int sum = 0;
	int tot = 0;
	CassaforteRec(n, k, 0, comb, &sum,&tot);
	return;
}

int main() {
	float t = time(0);
	Cassaforte(7, 44);
	double c = time(0);
	printf("\nTempo esecuzione: %f secondi", (c - t));
	int tot = pow(7, 10);
	printf("\n\nSu %d combinazioni possibili", tot);
	return;
}