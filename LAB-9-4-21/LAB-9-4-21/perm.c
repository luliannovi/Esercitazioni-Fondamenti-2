#include <stdio.h>
#include <stdlib.h>

StampaPermutazioni(int* a, int n, int i) {
	if (i == n) {
		for (int k = 0; k < n; k++)
			printf("%d ", a[k]);
		printf("\n");
		return;
	}
	for (int k = i; k < n; k++) {
		int tmp = a[i];
		a[i] = a[k];
		a[k] = tmp;
		
		StampaPermutazioni(a, n, i+1);
		
		tmp = a[i];
		a[i] = a[k];
		a[k] = tmp;
		
	}
}


int main() {
	int a[] = { 1,2,3,4 };
	int* vcurr = calloc(4, sizeof(int));
	StampaPermutazioni(a, 4, 0);
	return 0;
}