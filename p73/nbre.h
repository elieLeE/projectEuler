#ifndef _NBRE_H_
#define _NBRE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../shared/nbre.h"
#include "../shared/alloc.h"

#define LIMITE 12000

#define DENOM_MIN 2
#define DENOM_MAX 3

void visuTab(unsigned int *tab, unsigned int taille);
bool abPrime(unsigned int n, unsigned int* tabDiv, unsigned int nbreDiv);
void remplissageTabDiviseur(unsigned int* tabDiv, unsigned int *nbreDiv, unsigned int n);
unsigned int nbreFracIrr(unsigned int denom);

#endif
