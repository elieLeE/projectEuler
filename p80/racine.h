#ifndef _RACINE_H_
#define _RACINE_H_

#include <stdio.h>
#include <stdlib.h>
#include "../shared/nbre.h"

#define NBRE_DIGITS 100

int nbreSoustraction(int n, int *deb, int *res);
int nextDeb(int impair);
int nextN(int a, int b);
unsigned int sum100DecimalDigits(int n);

#endif
