#include <stdlib.h>
#include <stdint.h>

void RecamanSub(int n, int i, int* ret) {
	if (i == n) {
		return;
	}
	if (ret[i-1] % i == 0) {
		ret[i] = ret[i-1] / i;
		RecamanSub(n, i + 1, ret);
	}
	else {
		ret[i] = (i) * ret[i-1];
		RecamanSub(n, i + 1, ret);
	}
}



int Recaman(int n) {
	if (n < 1)
		return -1;
	int * ret = malloc(n*sizeof(int));
	ret[0] = 1;
	RecamanSub(n, 1, ret);
	int a = ret[n-1];
	free(ret);
	return a;
}


