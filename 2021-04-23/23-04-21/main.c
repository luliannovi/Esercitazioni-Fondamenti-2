#include "gioielli.h"
#include <string.h>

int main(void) {

	/*int tagli[] = { 50,20,10,5,2,1 };
	int r[] = { 0,0,0,0,0,0 };
	memcpy(r,Monete(tagli, 6, 126),6*sizeof(int));
	free(r);
	free(tagli);*/
	size_t ok;
	Gioiello* y = malloc(3 * sizeof(Gioiello));
	y = CompraGioielli("gioielli_2.txt", 121, &ok);
	return 0;
}