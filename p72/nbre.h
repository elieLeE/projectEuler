#ifndef _NBRE_H_
#define _NBRE_H_

#include <stdio.h>
#include <stdbool.h>
#include "donnees.h"

bool isPrime(int nbre);
int nbreNbrePrime(int limite);
int phi(int nbre, int tab[], int);
void remplissageTabPrime(int tab[], int, int);
bool indiceFirstDiviseur(int nbre, int *indice, int tab[]);
void aff_tab(double tab[], int taille_tab);

bool nbrePrimeTab(int n, int generateur, int tab[]);
int phi2(int limite, int mul, int tab_prime[]);

long phiListe(int n, int maxPrime, liste l);

#endif
