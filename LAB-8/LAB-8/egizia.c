#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void FrazioneEgiziaRec(int n, int d) {
	int a;
	if (d % n == 0)
		a = d / n;
	else
		a = abs(d / n) + 1;
	printf("1/%d", a);
	if (d % n == 0)
		return;
	else {
		printf(" + ");
		FrazioneEgiziaRec(n * a - d, d * a);
	}

}


void FrazioneEgizia(int n, int d) {
	if (n <= 0 || d <= 0 || n >= d)
		printf("Impossibile convertire la frazione data in frazione egizia.");
	else {
		FrazioneEgiziaRec(n, d);
	}
	
	return;
}