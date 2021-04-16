#include <stdio.h>
#include <stdlib.h>

StampaPermutazioni(int* a,int n,int i) {
	for (int k = 0; k < n; k++)
		printf("%d ", a[k]);
	printf("\n");

	int tmp = a[i];
	a[i] = a[i + 1];
	a[i + 1] = tmp;
	StampaPermutazioni(a, n, i + 1);
}


int main() {
	int a[] = { 1,2,3,4 };
	StampaPermutazioni(a,4,0);
	return 0;
}