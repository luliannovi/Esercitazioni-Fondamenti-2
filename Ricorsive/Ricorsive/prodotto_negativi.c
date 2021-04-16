int ProdottoNegativi(int a, int b) {
	if (a == 1)
		return b;
	if (b == 1)
		return a;
	if (a == 0 || b == 0)
		return 0;
	if (a < 0 && b < 0) {
		return ProdottoNegativi(-a, -b);
	}
	else if (a > 0 && b < 0) {
		return b + ProdottoNegativi(a - 1, b);
	}
	else if (a < 0 && b > 0) {
		return a + ProdottoNegativi(a, b - 1);
	}
	else if (a > b && b < 0) {
		return a + ProdottoNegativi(a, b + 1);
	}
	else {
		return a + ProdottoNegativi(a, b - 1);
	}
}