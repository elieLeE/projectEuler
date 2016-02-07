#ifndef _NBRE_H_
#define _NBRE_H_

#include <stdio.h>
#include <stdbool.h>

#define TAILLE_TAB 78497
#define LIMITE 1000000

bool nbrePrime(int nbre);
int nbreNbrePrime(int limite);
double phi(int nbre, int tab[]);

void remplissageTabPrime(int tab[]);
bool indiceFirstDiviseur(int nbre, int *indice, int tab[]);

#endif
