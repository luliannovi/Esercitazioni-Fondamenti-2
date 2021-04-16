
unsigned long long Fattoriale(int n) {
	if (n < 0)
		return 0;
	if (n == 0) {
		return 1;
	}
	else
		return Fattoriale(n - 1) * n;
}
