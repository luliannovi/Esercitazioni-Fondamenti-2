#include <stdlib.h>
#include <string.h>
#include <stdio.h>
void BacktrackStrModRec(int n, int k, char* alfabeto, char* now, int i) {
	if (i == k) {
		printf("{");
		for (int p = 0; p < k; p++) {
			printf("%c", now[p]);
		}
		printf("}, ");
		return;
	}

	for (int p = 0; p < n; p++) {
		now[i] = alfabeto[p];
		BacktrackStrModRec(n, k, alfabeto, now, i + 1);
	}
}

void BacktrackStrMod(int n, int k) {
	if (n <= 0 || n > 26 || k <= 0)
		return;
	char alfabeto[26] = "abcdefghijklmnopqrstuvwxyz";
	char* now = malloc(k);
	BacktrackStrModRec(n, k, alfabeto, now, 0);
	free(now);
	return;
}

