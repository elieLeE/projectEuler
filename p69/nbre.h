#ifndef _NBRE_H_
#define _NBRE_H_

#include <stdio.h>
#include <stdbool.h>
#include "../shared/nbre.h"

#define ALGO_FAST 1

#if ALGO_FAST
#define TAILLE_TAB 200
#else
#define TAILLE_TAB 78497
#endif

#define LIMITE 1000000

bool nbrePrime(unsigned int nbre);
unsigned int nbreNbrePrime(unsigned int limite);
double phi(unsigned int nbre, unsigned int tab[]);

void remplissageTabPrime(unsigned int tab[]);
bool indiceFirstDiviseur(unsigned int nbre, unsigned int *indice, unsigned int tab[]);

#endif
