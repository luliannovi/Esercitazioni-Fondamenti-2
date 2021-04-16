#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

void OmbrelloniRec(int k, int n, int i, bool* vcurr, int cnt, int* nsol) {
	if (i == n)
	{	
		if (cnt == k) {
			for (int j = 0; j < n - 1; j++) {
				if (vcurr[j] == true && vcurr[j + 1] == true)
					return;
			}
			(*nsol)++;
			printf("%d) ", *nsol);
			for (int j = 0; j < n; j++) {
				printf("%d ", vcurr[j]);
			}
			printf("\n");
		}
		return;
	}

	vcurr[i] = 0;
	OmbrelloniRec(k, n, i + 1, vcurr, cnt, nsol);

	vcurr[i] = 1;
	cnt++;
	OmbrelloniRec(k, n, i + 1, vcurr, cnt, nsol);
}
int Ombrelloni(int k, int n) {
	if (k < 0 || n < 0)
		return 0;
	int nsol = 0;
	bool* vcurr = calloc(n, sizeof(bool));
	OmbrelloniRec(k, n, 0, vcurr, 0, &nsol);
	free(vcurr);
	return nsol;
}

