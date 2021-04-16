#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
int ContaOccorrenze(const char* filename, const char* str) {
	if (filename != NULL && str != NULL) {
		FILE* f = fopen(filename, "r");
		if (f != NULL){
			int cont = 0;
			size_t len = strlen(str);
			bool ok = false;
			while (feof(f)==0) {
				char c = fgetc(f);
				if (c == str[0]) {
					for (size_t i = 0; i < (len-1) && (feof(f) == 0); i++) {
						char k = fgetc(f);
						if (k != str[i + 1]) {
							ok = false;
							break;
						}
						else {
							ok = true;
							continue;
						}
					}
					if (ok == true)
						cont++;
				}
			}
			fclose(f);
			return cont;
		}
		else
			return 0;
	}
	else
		return 0;
}
