#include <stdlib.h>
#include <string.h>
#include <math.h>
void AToIrec(const char* str, int len, int i, int* ret) {
	if (i != strlen(str)) {
		*ret += (int)(str[i] - 48) * pow(10, len - 1);
		AToIrec(str, len - 1, i + 1, ret);
	}
}


int AToI(const char* str) {
	if (str == NULL)
		return 0;
	size_t len = strlen(str);
	int ret = 0;
	AToIrec(str, len,0, &ret);
	return ret;
}

