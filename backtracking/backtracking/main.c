#include <stdio.h>
void SubsetK(int n, int i, int k, int vcurr[], int count, int* nsol) {
	int j;
	if (count == k) { //count mi informa su quanti 1  ho già inserito
		printf("%d soluzione) ", *nsol+1);
		(*nsol)++;
		for (int j = 0; j < i; j++) {
			printf("%d ", vcurr[j]);
		}
		for (int j = i; j < n; j++) {
			printf("0 ");
		}
		printf("\n");
		return;
	}
	if (i == n) return; //controlla se ho già indagato le 3 linee
	vcurr[i] = 0;
	SubsetK(n, i + 1, k, vcurr, count, nsol);
	vcurr[i] = 1;
	count++;
	SubsetK(n, i + 1, k, vcurr, count, nsol);
}
void BacktrackSubset(int n, int i, int vcurr[], int* nsol) {
	if (i == n) { // stampa soluzione
		printf("%d) ", *nsol);
		(*nsol)++;
		for (int j = 0; j < n; j++) {
			printf("%d ", vcurr[j]);
		}
		printf("\n");
		return;
	}
	vcurr[i] = 0;
	BacktrackSubset(n, i + 1, vcurr, nsol);
	vcurr[i] = 1;
	BacktrackSubset(n, i + 1, vcurr, nsol);
}

void SumSubset(int vcurr[],int len, int index, int tot, int* nsol, int *vet) {
	if (tot == 0) {
		printf("%d) ", *nsol + 1);
		*nsol++;
		for (int y = 0; y < index; y++) {
			printf("%d) ", vet[y]);
		}
		return;
	}
	else if (index >= len)
		return;
	else if (tot < 0)
		SumSubset(vcurr, len, index + 1, tot - vcurr[index], nsol, vet);
	else if (tot > 0 && index<len) {
		SumSubset(vcurr, len, index + 1, tot-vcurr[index], nsol,vet);
	}
	

}

void Permutazioni(int n, int i, int vcurr[], int* nsol) {
	int j, tmp;
	if (i == n) { // stampa soluzione
		printf("%d) ", *nsol);
		(*nsol)++;
		for (int j = 0; j < n; j++) {
			printf("%d ", vcurr[j]);
		}
		printf("\n");
		return;
	}
	for (int j = i; j < n; j++) {
		tmp = vcurr[i]; vcurr[i] = vcurr[j]; vcurr[j] = tmp;
		Permutazioni(n, i + 1, vcurr, nsol);
		tmp = vcurr[i]; vcurr[i] = vcurr[j]; vcurr[j] = tmp;
	}
}

int main(void) {
	int* v = malloc(3 * sizeof(int));
	int a=0;
	int y = 0;
	//SubsetK(5, 0, 2, v, a, &y); // quanti sottoinsiemi da 2 '1' su 5 linee
	BacktrackSubset(3, 0, v, &a);

	int ar[] = { 1,2,3 };
	//int tot = 0;
	//int* vet = malloc(4 * sizeof(int));
	//SumSubset(ar, 4, 0, 9, &tot, vet);
	a = 0;
	Permutazioni(3, 0, ar, &a);
}

