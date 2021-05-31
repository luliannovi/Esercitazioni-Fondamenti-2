#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int hailstone(int n, int i, int* now) {
	
	now[i] = n;
	if (n == 1) {
		return i + 1;
	}
	if (n % 2 == 0) {
		return hailstone(n/2, i+1, now);
	}else
		return hailstone(3*n + 1, i+1, now);
}

int main(int argc, char** argv) {
	if (argc != 2)
		return -1;
	int n = atoi(argv[1]);
	if (n <= 0)
		return 0;
	int k = n;
	int i = 0;
	for (i = 1; k != 1; i++) {
		if (k % 2 == 0)
			k = k / 2;
		else
			k = k * 3 + 1;
	}
	int* now = malloc(sizeof(int)*i);
	k =hailstone(n, 0, now);
	for (int i = 0; i < k; i++) {
		printf("%d", now[i]);
		if (i + 1 < k)
			printf(", ");
	}
	free(now);
	return k;
}