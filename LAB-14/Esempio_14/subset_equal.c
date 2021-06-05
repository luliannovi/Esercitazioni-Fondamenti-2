#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

int Present(int* ret, int k,int dim) {
	for (int i = 0; i < dim; i++) {
		if (ret[i] == k)
			return 0;
	}
	return 1;
}

int corretta_sequenza(int* ret, int dim) {
	for (int i = 1; i < dim; i++) {
		if (ret[i] <= ret[i - 1])
			return 0;
	}
	return 1;
}

void SubsetEqualSub(int n, int s, int i,int * ret, int tot_in_sol, int sum_now) {
	if (sum_now == s && corretta_sequenza(ret,tot_in_sol)==1) {
		for (int k = 0; k < tot_in_sol; k++) {
			printf("%d ", ret[k]);
		}
		printf("\n");
		return;
	}
	if (i == n || sum_now >s)
		return;

	for (int j = i; j < n; j++) {
		if (Present(ret, j + 1, tot_in_sol)==1 ) {
			ret[i] = j + 1;
			
			SubsetEqualSub(n, s, i + 1, ret, tot_in_sol + 1, sum_now + ret[i]);
		}
	}
}


void SubsetEqual(int n, int s) {
	if (n <= 0 || s <= 0)
		return;
	int* ret = malloc(n * sizeof(int));
	SubsetEqualSub(n, s, 0, ret, 0, 0);
	return;
}

