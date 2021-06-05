#include <stdlib.h>

int MCD(int m, int n) {

	if (m >= n) {
		if (n == 0)
			return m;
		return MCD(n, m % n);
	}
	else {
		if (m == 0)
			return n;
		return MCD(m, n % m);
	}
}