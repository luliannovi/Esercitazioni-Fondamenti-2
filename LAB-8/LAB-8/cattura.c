#include <stdlib.h>
#include <stdio.h>

void CacciatorePredaRec(const char* v, size_t v_size, int u, int catturate, int* now, int tot_cacciatori, int * totbest, int *best_vector) {
	
	for (int i = 0; i < v_size; i++) {
		if ((v[i] == 'c' || v[i] == 'C') && now[i] == -1) {
			for (int k = 0; k < v_size; k++) {
				if ((v[k] == 'p' || v[k] == 'P') && now[k] == -1 && abs(i-k)<=u) {
					now[k] = -2;
					now[i] = k;
					if (catturate + 1 > *totbest) {
						*totbest = catturate + 1;
						for (int p = 0; p < v_size; p++) {
							best_vector[p] = now[p];
						}
					}
					CacciatorePredaRec(v, v_size, u, catturate + 1 , now, tot_cacciatori, totbest, best_vector);
					now[k] = -1;
					now[i] = -1;
				}
			}
		}

	}
}



int* CacciatorePreda(const char* v, size_t v_size, int u) {
	int* now = malloc(v_size * sizeof(int));
	for (int k = 0; k < v_size; k++) {
		now[k] = -1;
	}
	
	
	int t = -1;
	for (int k = 0; k < v_size; k++) {
		if (v[k] == 'c' || v[k] == 'C')
			t++;
	}
	if (t == -1)
		return now;

	int z = -1;
	for (int k = 0; k < v_size; k++) {
		if (v[k] == 'p' || v[k] == 'P')
			z++;
	}
	if (z == -1)
		return now;
	int* best = malloc(v_size * sizeof(int));
	int totale_migliore = 0;
	CacciatorePredaRec(v, v_size, u, 0, now, t, &totale_migliore, best);

	free(now);
	return best;
}
/*
int main(void) {
	char v[5] = { 'C','p','p','C','p' };
	CacciatorePreda(v, 5, 1);
	return 0;
}*/