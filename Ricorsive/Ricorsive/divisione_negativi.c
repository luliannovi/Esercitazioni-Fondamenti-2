#include <limits.h>
int DivisioneNegativi(int a, int b) {
	if (b == 0 )
		return INT_MAX;
	if (a == 0)
		return 0;
	if (a > 0 && b > 0 && a < b)
		return 0;
	if (a < 0 && b < 0) {
		return DivisioneNegativi(-a, -b);
	}
	else if (a < 0 || b < 0)
		return DivisioneNegativi(a + b, b) - 1;
	else
		return DivisioneNegativi(a - b, b) + 1;
}
