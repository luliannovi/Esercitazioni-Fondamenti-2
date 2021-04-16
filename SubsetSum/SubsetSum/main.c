#include <stdlib.h>
#include <stdio.h>

void Permutazioni(int i, int n, int* vcurr,int * tot) {
	int tmp;
	if (i == n) {
		*tot = (*tot) + 1;
		printf("%d) ", *tot);
		for (int p = 0; p < n; p++) {
			printf("%d ", vcurr[p]);
		}
		printf("\n");
		return;

	}
	for (int j = i; j < n; j++) {
		tmp = vcurr[i];
		vcurr[i] = vcurr[j];
		vcurr[j] = tmp;
		Permutazioni(i + 1, n, vcurr,tot);
		tmp = vcurr[i];
		vcurr[i] = vcurr[j];
		vcurr[j] = tmp;
	}
}

int main(void) {
	int v[] = { 1,2,3,4 };
	int a = 0;
	Permutazioni(0, 4, v, &a);
}