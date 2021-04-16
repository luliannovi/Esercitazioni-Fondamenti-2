#include <stdlib.h>
#include <stdint.h>
#include <limits.h>
int Minimo(int* v, int v_size) {
	if (v_size == 1)
		return *v;
	else {
		int* m = malloc((v_size - 1) * sizeof(int));
		for (int i = 0; i < v_size-1; i++) {
			m[i] = v[i + 1];
		}
		int k = Minimo(m, v_size - 1);
		if (*v < k) {
			int tmp = *v;
			free(m);
			return tmp;
		}
		else {
			free(m);
			return k;
		}
	}
}
/*
int main(void) {
	int* v = malloc(6 * sizeof(int));
	v[0] = 0;
	v[1] = 2;
	v[2] = 3;
	v[3] = -5;
	v[4] = 5;
	v[5] = 6;
	return Minimo(v, 6);
}*/