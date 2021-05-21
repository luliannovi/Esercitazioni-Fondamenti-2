#define _CRT_SECURE_NO_WARNINGS
#include "elemtype.h"

#include <string.h>
#include <stdlib.h>
#include <string.h>

#define _unused(x) ((void)(x))

int ElemCompare(const ElemType *e1, const ElemType *e2) {
    return strcmp(e1->name,e2->name);
}

ElemType ElemCopy(const ElemType *e) {
    return *e;
}

void ElemSwap(ElemType *e1, ElemType *e2) {
    ElemType tmp = *e1;
    *e1 = *e2;
    *e2 = tmp;
}

void ElemDelete(ElemType *e) {
    return;
}

int ElemRead(FILE *f, ElemType *e) {
    return fscanf(f, "%s", e->name);
}

int ElemReadStdin(ElemType *e) {
    return ElemRead(stdin, e);
}

void ElemWrite(const ElemType *e, FILE *f) {
    fprintf(f, "%s", e->name);
}

void ElemWriteStdout(const ElemType *e) {
    ElemWrite(e, stdout);
}