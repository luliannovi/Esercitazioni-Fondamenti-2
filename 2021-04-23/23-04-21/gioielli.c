#include "gioielli.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
Gioiello* CompraGioielli(const char* filename, float budget, size_t* ret_size) {
	if (filename == NULL)
		return NULL;

	
	FILE* f = fopen(filename, "r");
	if (f == NULL)
		return NULL;
	Gioiello* red = malloc(0);
	int tot = 0;
	int n = 0;
	while (true) {
		tot += 1;
		red = realloc(red, tot * sizeof(Gioiello));
		n=fscanf(f, "%d %f %f", &red[tot - 1].codice, &red[tot - 1].peso, &red[tot - 1].prezzo);
		if (n != 3) {
			tot -= 1;
			break;
		}
	}
	fclose(f);
	float* rapporti = calloc(tot, sizeof(float));
	for (int i = 0; i < tot; i++) {
		rapporti[i] = red[i].peso / red[i].prezzo;
	}
	bool* ok = calloc(tot, sizeof(bool));
	float max = 0.0;
	float prezzo_ora = 0;
	int k;
	int fin = 0;
	int i;
	int controlled = 0;
	while (prezzo_ora < budget && controlled<tot) {
		for (i = 0,max=0; i < tot; i++) {
			if (rapporti[i] > max) {
				max = rapporti[i];
				k = i;
			}
		}
		rapporti[k] = 0;
		controlled += 1;
		if ((prezzo_ora + red[k].prezzo) <= budget) {
			ok[k] = true;
			fin += 1;
			prezzo_ora += red[k].prezzo;
		}
	}
	Gioiello* ritorno = malloc(fin * sizeof(Gioiello));
	for(int i=0,k=0;i<tot;i++){
		if (ok[i] == true) {
			ritorno[k] = red[i];
			k += 1;
		}
	}
	*ret_size = fin;
	free(ok);
	free(rapporti);
	free(red);
	return ritorno;

}