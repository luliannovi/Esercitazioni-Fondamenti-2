#include <stdlib.h>



void InsertionSort(int* v, size_t v_size) {
	if (v == NULL)
		return;
	for (int i = 1; i < v_size; i++) {
		for (int k = 0; k < i ; k++) {
			if (v[i] <= v[k]) {
				int tmp = v[i];
				for (int j = i - 1; j >= k; j--) {
					v[j + 1] = v[j];
				}
				v[k] = tmp;
			}
		}
	}
}


