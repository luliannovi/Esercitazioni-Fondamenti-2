#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

void BabboNataleRec(const int* pacchi, size_t pacchi_size, int p, unsigned int i, bool* vcurr, bool* vbest, int* max, int cnt, int sum) {
	if (sum > p)
		return;
	if (i == pacchi_size) {
		if (cnt > *max) {
			*max = cnt;
			for (size_t j = 0; j < pacchi_size; j++) {
				vbest[j] = vcurr[j];
			}
			return;
		}
		else
			return;
	}

	vcurr[i] = 0;
	BabboNataleRec(pacchi, pacchi_size, p, i + 1, vcurr, vbest, max, cnt, sum);

	vcurr[i] = 1;
	BabboNataleRec(pacchi, pacchi_size, p, i + 1, vcurr, vbest, max, cnt+1, sum+pacchi[i]);

}

void BabboNatale(const int* pacchi, size_t pacchi_size, int p) {
	if (p < 0)
		return;
	bool* vcurr = calloc(pacchi_size, sizeof(bool));
	bool* vbest = calloc(pacchi_size, sizeof(bool));
	int max = 0;
	BabboNataleRec(pacchi, pacchi_size, p, 0, vcurr,vbest, &max, 0, 0);
	for (size_t i = 0; i < pacchi_size; i++) {
		printf("%d ", vbest[i]);
	}
	free(vcurr);
	free(vbest);
	return;
}

