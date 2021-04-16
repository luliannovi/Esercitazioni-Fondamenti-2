#include <string.h>
#include <stdlib.h>

void ToUpper(char* str) {
	if (str != NULL) {
		int len = strlen(str);
		for (int i = 0; i < len; i++) {
			if (*(str + i ) >= 97 && *(str + i) <= 122) {
				*(str + i) = *(str + i) - 32;
			}
		}
	}
}