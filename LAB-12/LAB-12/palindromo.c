#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
bool IsPalindromoRec(char* str, int a, int b) {
	if (a < b) {
		if (str[a] == str[b]) {
			return true && IsPalindromoRec(str, a + 1, b - 1);
		}
		else
			return false;
	}if (a == b) {
		if (str[a] == str[b]) {
			return true ;
		}
		else
			return false;
	}
	else {
		return true;
	}
}


bool IsPalindromo(const char* str) {
	if (str == NULL)
		return false;
	if (strlen(str) == 0 || strlen(str) == 1)
		return true;
	size_t len = strlen(str);
	return IsPalindromoRec(str, 0, len - 1);

}

