#ifndef _NBRE_H_
#define _NBRE_H_

#include <stdio.h>
#include <stdbool.h>

#define TAILLE_TAB 664579
#define LIMITE 10000000

bool nbrePrime(int nbre);
int nbreNbrePrime(int limite);
double phi(int nbre, int tab[]);
void nbreToDigits(int *tab, int n);
void reInitTab(int *tab);
bool permutation(int n, int phiN);

void remplissageTabPrime(int tab[]);
bool indiceFirstDiviseur(int nbre, int *indice, int tab[]);

#endif
