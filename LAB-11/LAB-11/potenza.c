#include <stdlib.h>

int PotenzaRec(int a, int b, int i, int tot) {
	if (i == b)
		return tot;
	return PotenzaRec(a, b, i + 1, tot * a);
}


int Potenza(int a, int b) {
	if (b == 0 || (a == 0 && b == 0))
		return 1;
	return PotenzaRec(a, b, 0, 1);
}

