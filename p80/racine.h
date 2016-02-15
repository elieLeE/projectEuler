#ifndef _RACINE_H_
#define _RACINE_H_

#include <stdio.h>
#include <stdlib.h>
#include "../shared/nbre.h"
#include "gmp.h"

#define NBRE_DIGITS 100

int nbreSoustraction(mpz_t n, mpz_t *deb, mpz_t *res);
void nextDeb(mpz_t* impair);
void nextN(mpz_t *a, mpz_t);
unsigned int sum100DecimalDigits(int n);

#endif
