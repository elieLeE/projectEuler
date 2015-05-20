#ifndef _NBRE_H_
#define _NBRE_H_

#include <stdio.h>
#include <stdbool.h>
#include "donnees.h"

int nextNbrePrime(int prime);
bool isPrime(int nbre);
char nbreDigit(short nbre);
bool isPerm(element e1, element e2);
bool isPermTab(element e, element tab[], char nbreEval);

#endif
