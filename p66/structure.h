#ifndef _STRUCTURE_H_
#define _STRUCTURE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct alpha alpha;
struct alpha{
    long a, b, n;
};

long normeAlpha(alpha a);
alpha alphaCarreSur2(alpha a);
alpha alphaCubeSur8(alpha a);
char* visuAlpha(alpha a);

#endif
