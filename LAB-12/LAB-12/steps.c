#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void StepsRec(int n, int altezza, int* v,int len_now,int * soluzioni) {
	if (altezza == n) {
		*soluzioni = *soluzioni +1;
		printf("[");
		for (int p = 0; p < len_now; p++) {
			printf("%d", v[p]);
			if (p + 1 == len_now)
				printf("], ");
			else
				printf(", ");
		}
		return;
	}
	if (altezza > n)
		return;

	for (int k = 1; k <= 3; k++) {
		if (altezza + k <= n) {
			v[len_now] = k;
			
			StepsRec(n, altezza + k, v, len_now + 1, soluzioni);
		}
		else
			break;
	}

}

int Steps(int n) {
	if (n <= 0)
		return 0;
	int* v = malloc(n * sizeof(int));
	int soluzioni = 0;
	StepsRec(n, 0, v, 0, &soluzioni);
	free(v);
	return soluzioni;
}

