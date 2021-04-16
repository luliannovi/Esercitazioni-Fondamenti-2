#include <string.h>
#include <stdio.h>

void AllStringSub(unsigned int n,char * vet,unsigned int i,unsigned int *cont) {
	if (i == n) {
		(*cont)++;
		fprintf(stdout, "%d) %c%c%c", *cont, vet[0], vet[1], vet[2]);
		printf("\n");
		return;
	}

	vet[i] = 'a';
	AllStringSub(n, vet, i+1,cont);

	vet[i] = 'b';
	AllStringSub(n, vet, i+1,cont);

	vet[i] = 'c';
	AllStringSub(n, vet, i+1,cont);
	return;
}
int AllString(unsigned int n) {
	char* vet = malloc(n);
	int cont=0;
	AllStringSub(n,vet,0,&cont);
		free(vet);
	return 0;
 }

int main(void) {
	AllString(3);
	return 0;
}