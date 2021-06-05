#include <string.h>
#include <stdlib.h>

void ReverseStringRec(const char* str, int i,char * ret, size_t len) {
	if (len - i == 0) {
		ret[i] = str[len - i];
		return;
	}
	ret[i] = str[len - i];
	ReverseStringRec(str, i + 1, ret, len);
}


char* ReverseString(const char* str) {
	if (str == NULL)
		return NULL;
	size_t len = strlen(str);
	if (len == 0)
		return str;
	char* ret = malloc(len+1);
	ret[len] = 0x00;
	ReverseStringRec(str, 0, ret, len-1);
	return ret;
}

